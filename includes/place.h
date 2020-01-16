/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ecelsa <ecelsa@school21.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:09:32 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/16 14:49:46 by Ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACE_H
# define PLACE_H

# include "fillit.h"

void	border_right(t_uint64 *arr, int sq);
void	border_bottom(t_uint64 *arr, int sq);
int		check_set(t_fillit *tetr);
void	place_tetr(t_fillit *tetr);
int		arrcmp(t_uint64 *arr1, t_uint64 *arr2, int arr_size);

#endif