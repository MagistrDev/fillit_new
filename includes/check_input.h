/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ecelsa <ecelsa@school21.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:59:52 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/16 12:24:07 by Ecelsa           ###   ########.fr       */
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