/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:21:32 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/24 23:15:59 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "fillit.h"

void	fil_ch_lf(char *buf, int col_tetr, int sq);
void	print_map(t_fillit *tetr, int sq, int col_tetr);

#endif
