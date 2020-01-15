/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:59:52 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/15 00:01:20 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_INPUT_H
# define CHECK_INPUT_H

# include "fillit.h"

void		conv_shtoarr(t_fillit *fig);
void		sh_tl_bit(t_fillit *fig);
void		ft_check_input(int argc, char **argv);
char		*ft_input_arg(int argc, char **argv);
t_fillit	*create_mas(int argc, char **argv);
int			check_buf(char *buf);

#endif