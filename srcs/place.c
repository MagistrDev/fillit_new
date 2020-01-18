/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:09:03 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/18 19:41:02 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		arrcmp(t_uint64 *arr1, t_uint64 *arr2, int arr_size)
{
	int		cmp;
	int		i;

	i = -1;
	cmp = 0;
	while (++i < arr_size)
	{
		if (*(arr1 + i) & *(arr2 + i))
			cmp++;
	}
	return (cmp);
}

void	border_right(t_uint64 *arr, int sq)
{
	int			i;
	t_uint64	mask;

	mask = mask_shift(16 - sq);
	i = -1;
	while (++i < 4)
	{
		*(arr + i) |= mask;
		*(arr + i) <<= 16;
		*(arr + i) |= mask;
		*(arr + i) <<= 16;
		*(arr + i) |= mask;
		*(arr + i) <<= 16;
		*(arr + i) |= mask;
	}
}

void	border_bottom(t_uint64 *arr, int sq)
{
	t_uint64	mask;
	short		*sub;

	sub = (short*)arr;
	mask = 0xffffffffffffffff;
	while (sq < 16)
	{
		*(sub + sq) = mask;
		sq++;
	}
}

int		check_set_all(t_fillit *tetr)
{
	int			flag;
	int			col_tetr;
	int			i;

	i = -1;
	col_tetr = (tetr->prev - tetr) + 1;
	flag = 1;
	while (++i < col_tetr)
		flag = (!((tetr + i)->set)) ? 0 : 1;
	return (flag);
}

void	sh_tet_nextline(t_fillit *fig, int sq)
{
	(void)sq;
	shift_bit_arr_left(fig->tetr, 4, 16);
	
}

void	place_tetr(t_fillit *tetr, t_uint64 *map, int sq)
{
	t_uint64	b_r[4];
	t_uint64	b_b[4];

	sq = 4;
	border_right(b_r, sq);
	border_bottom(b_b, sq);
	if (!arrcmp(tetr->tetr, map, 4))
		;
}
