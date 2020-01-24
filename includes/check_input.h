/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:59:52 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/24 22:21:35 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_INPUT_H
# define CHECK_INPUT_H

# include "fillit.h"

char		*input_arg(int argc, char **argv);
void		sh_tl_bit(t_fillit *fig);
int			conv_chtosh(t_fillit *fig);
void		conv_shtoarr(t_fillit *fig);
void		search_height_tetr(t_fillit *fig);
void		search_width_tetr(t_fillit *fig);
void		check_input(int argc, char **argv);
int			fil_struct(t_fillit *tetr, char *buf, int n_elem, int col_tetr);
t_fillit	*create_mas(int argc, char **argv);
int			check_buf(char *buf);
int			valid_tet(t_fillit *tetr, int col_tetr);

#endif
