/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:09:03 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/22 20:36:32 by ecelsa           ###   ########.fr       */
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
			cmp = 1;
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
		*(arr + i) = 0;
		*(arr + i) |= mask;
		*(arr + i) >>= 16;
		*(arr + i) |= mask;
		*(arr + i) >>= 16;
		*(arr + i) |= mask;
		*(arr + i) >>= 16;
		*(arr + i) |= mask;
	}
}

void	border_bottom(t_uint64 *arr, int sq)
{
	t_uint64	mask;
	short		*sub;

	sub = (short*)arr;
	mask = 0xffffffffffffffff;
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
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
		if (!((tetr + i)->set))
			flag = 0;
	return (flag);
}

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
