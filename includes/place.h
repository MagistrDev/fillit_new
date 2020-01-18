/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:09:32 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/18 17:50:14 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACE_H
# define PLACE_H

# include "fillit.h"

void	border_right(t_uint64 *arr, int sq);
void	border_bottom(t_uint64 *arr, int sq);
int		check_set_all(t_fillit *tetr);
void	place_tetr(t_fillit *tetr, t_uint64 *map, int sq);
int		arrcmp(t_uint64 *arr1, t_uint64 *arr2, int arr_size);

#endif
