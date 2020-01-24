/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:19:00 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/25 00:24:56 by ecelsa           ###   ########.fr       */
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
