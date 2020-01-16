/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_bits.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ecelsa <ecelsa@school21.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:28:19 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/16 12:24:33 by Ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIFT_BITS_H
# define SHIFT_BITS_H
# include "fillit.h"

t_uint64	ft_mask_shift(int shift);
void		ft_shift_bit_arr(t_uint64 *array, int arr_size, int shift);
void		ft_shift_bit_arr_left(t_uint64 *array, int arr_size, int shift);
void		ft_shift_bit_arr_right(t_uint64 *array, int arr_size, int shift);

#endif
