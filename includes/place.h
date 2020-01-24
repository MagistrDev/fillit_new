/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:09:32 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/24 11:14:43 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACE_H
# define PLACE_H

# include "fillit.h"

void	border_right(t_uint64 *arr, int sq);
void	border_bottom(t_uint64 *arr, int sq);
int		check_set_all(t_fillit *tetr);
int		fig_cmp(t_fillit *fig, t_uint64 *map, int sq);
int		place_tetr(t_fillit *tetr, t_uint64 *map, int sq);
int		arrcmp(t_uint64 *arr1, t_uint64 *arr2, int arr_size);
void	sh_tet_nextline(t_fillit *fig, int sq);
void	remove_fig(t_fillit *fig, t_uint64 *map);
void	place_tetr_on_map(t_fillit *fig, t_uint64 *map);

#endif
