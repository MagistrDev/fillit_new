/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:18:55 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/22 20:38:47 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_uint64	mask_shift(int shift)
{
	t_uint64	r;
	int			i;

	i = (shift >= 0) ? shift : -(shift);
	r = 0;
	while (i--)
		r |= (t_uint64)1 << (i + ((shift > 0) ? (64 - shift) : 0));
	return (r);
}

void		shift_bit_arr(t_uint64 *arr, int arr_size, int shift)
{
	if (shift >= 0)
		shift_bit_arr_left(arr, arr_size, shift);
	else
	{
		shift *= -1;
		shift_bit_arr_right(arr, arr_size, shift);
	}
}

void		shift_bit_arr_left(t_uint64 *arr, int arr_size, int shift)
{
	t_uint64	mask;
	int			sh;
	int			i;

	i = arr_size;
	sh = shift;
	while (sh > 64)
		sh -= 64;
	mask = mask_shift(sh);
	while (--i >= 0)
	{
		if (sh == 64)
			arr[i] = (i > 0) ? arr[i - 1] : 0;
		else
		{
			arr[i] <<= sh;
			if (i)
				arr[i] |= (arr[i - 1] & mask) >> (64 - sh);
		}
	}
	if (shift > 63)
		shift_bit_arr_left(arr, arr_size, shift - sh);
}

void		shift_bit_arr_right(t_uint64 *arr, int arr_size, int shift)
{
	t_uint64	mask;
	int			sh;
	int			i;

	i = 0;
	sh = shift;
	arr_size--;
	while (sh > 64)
		sh -= 64;
	mask = mask_shift(-1 * sh);
	while (i < arr_size)
	{
		if (sh == 64)
			arr[i] = (i < arr_size) ? arr[i + 1] : 0;
		else
		{
			arr[i] >>= sh;
			if (i < arr_size)
				arr[i] |= (arr[i + 1] & mask) << (64 - sh);
		}
		i++;
	}
	if (shift > 63)
		shift_bit_arr_right(arr, arr_size, shift - sh);
}
