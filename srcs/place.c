/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:09:03 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/17 20:37:19 by ecelsa           ###   ########.fr       */
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

	mask = ft_mask_shift(16 - sq);
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

int		check_set(t_fillit *tetr)
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

void	place_tetr(t_fillit *tetr)
{
	while (!(check_set(tetr)))
	{
	}
	(void)tetr;
}
