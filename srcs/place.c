/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:09:03 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/18 22:08:36 by ecelsa           ###   ########.fr       */
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

int		place_tetr(t_fillit *tetr, t_uint64 *map, int sq)
{
	t_uint64	b_r[4];
	t_uint64	b_b[4];
	int			flag;

	flag = 0;
	border_right(b_r, sq);
	border_bottom(b_b, sq);
	while (!flag)
	{
		if (arrcmp(tetr->tetr, map, 4))
		{
			shift_bit_arr(tetr->tetr, 4, 1);
			if (arrcmp(tetr->tetr, b_r, 4))
				sh_tet_nextline(tetr, sq);
			if (arrcmp(tetr->tetr, b_b, 4))
				break ;
		}
		else
			flag = 1;
	}
	if (flag)
		place_tetr_on_map(tetr, map);
	return (tetr->set);
}
