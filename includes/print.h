/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:21:32 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/22 23:26:36 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "fillit.h"

void	print_tetr(t_fillit *tetr, int sq);
void	print_map(t_fillit *tetr, int sq);
void	test(t_uint64 *arr, int sq);
void	print_table(t_fillit *tetr, int sq); 

#endif
