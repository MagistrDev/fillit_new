/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:50:02 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/25 01:31:17 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const short		g_valid[19] = {
	0xf, 0x1111, 0x33, 0x17, 0x47, 0x71, 0x74, 0x311, 0x113, 0x223, 0x322,
	0x27, 0x232, 0x72, 0x131, 0x63, 0x132, 0x36, 0x231
};

void	out_of_bottom_border(t_fillit *tetr, int *i, t_uint64 *map, int *sq)
{
	conv_shtoarr(tetr + *i);
	(*i)--;
	remove_fig(tetr + *i, map);
	if (*i == -1)
	{
		(*sq)++;
		*i = 0;
	}
	else
		shift_bit_arr((tetr + *i)->tetr, 4, 1);
}

void	algorithm(t_fillit *tetr, t_kostil *var, t_uint64 *map)
{
	while (var->i < var->col_tetr)
	{
		conv_shtoarr(tetr + var->i);
		while ((var->err_cmp = fig_cmp(tetr + var->i, map, var->sq)))
		{
			if (var->err_cmp & 4)
				out_of_bottom_border(tetr, &var->i, map, &var->sq);
			else
			{
				if ((var->err_cmp & 1) && !(var->err_cmp & 2))
					shift_bit_arr((tetr + var->i)->tetr, 4, 1);
				if (var->err_cmp & 2)
					sh_tet_nextline(tetr + var->i, var->sq);
			}
		}
		place_tetr(tetr + var->i, map, var->sq);
		var->i++;
	}
}

int		main(int argc, char **argv)
{
	t_fillit	*tetr;
	t_uint64	map[4];
	t_kostil	var;

	if (!(tetr = create_mas(argc, argv)))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_bzero(map, 32);
	var.col_tetr = tetr->prev - tetr + 1;
	var.sq = ft_sqrt(var.col_tetr * 4);
	var.err_cmp = 0;
	var.i = 0;
	if (valid_tet(tetr, var.col_tetr))
	{
		algorithm(tetr, &var, map);
		print_map(tetr, var.sq, var.col_tetr);
	}
	else
		ft_putstr("error\n");
	free(tetr);
	tetr = NULL;
	return (0);
}
