/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:50:02 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/19 02:18:41 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_fillit	*tetr;
	t_uint64	map[4];
	int			i;
	int			col_tetr;
	int			err_cmp;
	int			sq;

	printf("start\n");
	sq = 4;
	err_cmp = 0;
	i = 4;
	while (i--)
		map[i] = 0;
	tetr = create_mas(argc, argv);
	i = 0;
	col_tetr = tetr->prev - tetr + 1;	
	while (i < col_tetr)
	{
		conv_shtoarr(tetr + i);
		while ((err_cmp = fig_cmp(tetr + i, map, sq)))
		{
			if (err_cmp & 4)
			{
				conv_shtoarr(tetr + i);
				i--;
				remove_fig(tetr + i, map);
				if (i == -1)
					sq++;
				else 
					shift_bit_arr((tetr + i)->tetr, 4, 1);
			}
			else 
			{
				if (err_cmp & 1)
					shift_bit_arr((tetr + i)->tetr, 4, 1);
				if (err_cmp & 2)
					sh_tet_nextline(tetr + i, sq);
			}
		}
		i++;
	}
	free(tetr);
	tetr = NULL;
	return (0);
}
