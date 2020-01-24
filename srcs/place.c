/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:09:03 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/25 00:27:43 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	sh_tet_nextline(t_fillit *fig, int sq)
{
	shift_bit_arr_left(fig->tetr, 4, 16 - (sq - fig->width_tetr + 1));
}

void	place_tetr_on_map(t_fillit *fig, t_uint64 *map)
{
	int		i;

	i = 4;
	while (i--)
		map[i] |= fig->tetr[i];
	fig->set = 1;
}

int		fig_cmp(t_fillit *fig, t_uint64 *map, int sq)
{
	t_uint64	b_r[4];
	t_uint64	b_b[4];
	int			cmp;

	cmp = 0;
	border_right(b_r, sq);
	border_bottom(b_b, sq);
	if (arrcmp(fig->tetr, map, 4))
		cmp |= 1;
	if (arrcmp(fig->tetr, b_r, 4))
		cmp |= 2;
	if (arrcmp(fig->tetr, b_b, 4))
		cmp |= 4;
	return (cmp);
}

void	remove_fig(t_fillit *fig, t_uint64 *map)
{
	map[0] ^= fig->tetr[0];
	map[1] ^= fig->tetr[1];
	map[2] ^= fig->tetr[2];
	map[3] ^= fig->tetr[3];
	fig->set = 0;
}

int		place_tetr(t_fillit *tetr, t_uint64 *map, int sq)
{
	(void)sq;
	place_tetr_on_map(tetr, map);
	return (tetr->set);
}
