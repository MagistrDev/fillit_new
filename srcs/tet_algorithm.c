/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:19:00 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/24 15:02:22 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetcmp(t_ulli *table, t_uint64 *tetr, int sq)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	(void)sq;
	while (i < 4)
	{
		if (table[i] & tetr[i])
			r |= 1;
		i++;
	}
	return (r);
}

// void	tet_algorithm(t_fillit *tetr, t_uint64 *map, int sq)
// {
// 	while (i < col_tetr)
// 	{
// 		conv_shtoarr(tetr + i);
// 		while ((err_cmp = fig_cmp(tetr + i, map, sq)))
// 		{
// 			if (err_cmp & 4)
// 			{
// 				conv_shtoarr(tetr + i);
// 				i--;
// 				remove_fig(tetr + i, map);
// 				if (i == -1)
// 				{
// 					sq++;
// 					i = 0;
// 				}
// 				else
// 					shift_bit_arr((tetr + i)->tetr, 4, 1);
// 			}
// 			else
// 			{
// 				if ((err_cmp & 1) && !(err_cmp & 2))
// 					shift_bit_arr((tetr + i)->tetr, 4, 1);
// 				if (err_cmp & 2)
// 					sh_tet_nextline(tetr + i, sq);
// 			}
// 		}
// 	}
// }