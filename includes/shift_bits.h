/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_bits.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:28:19 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/18 18:05:00 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIFT_BITS_H
# define SHIFT_BITS_H
# include "fillit.h"

t_uint64	mask_shift(int shift);
void		shift_bit_arr(t_uint64 *array, int arr_size, int shift);
void		shift_bit_arr_left(t_uint64 *array, int arr_size, int shift);
void		shift_bit_arr_right(t_uint64 *array, int arr_size, int shift);

#endif
