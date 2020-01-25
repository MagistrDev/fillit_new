/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:50:42 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/25 19:12:13 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# if __APPLE__ || __MACH__ || __linux__
#  include <unistd.h>
# elif __WINDOWS__
#  include <io.h>
# endif
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef unsigned long long		t_uint64;
typedef unsigned long long int	t_ulli;
typedef struct	s_fillit
{
	char			tetr_char[22];
	unsigned short	tetr_bit;
	t_uint64		tetr[4];
	int				width_tetr;
	int				height_tetr;
	int				set;
	struct s_fillit	*next;
	struct s_fillit	*prev;
}				t_fillit;

typedef struct	s_main_struct
{
	int			i;
	int			col_tetr;
	int			err_cmp;
	int			sq;
}				t_kostil;

char			*input_arg(int argc, char **argv);
void			sh_tl_bit(t_fillit *fig);
int				conv_chtosh(t_fillit *fig);
void			conv_shtoarr(t_fillit *fig);
void			search_height_tetr(t_fillit *fig);
void			search_width_tetr(t_fillit *fig);
void			check_input(int argc, char **argv);
int				fil_struct(t_fillit *tetr, char *buf, int n_elem, int col_tetr);
t_fillit		*create_mas(int argc, char **argv);
int				check_buf(char *buf);
int				valid_tet(t_fillit *tetr, int col_tetr);
void			border_right(t_uint64 *arr, int sq);
void			border_bottom(t_uint64 *arr, int sq);
int				check_set_all(t_fillit *tetr);
int				fig_cmp(t_fillit *fig, t_uint64 *map, int sq);
int				place_tetr(t_fillit *tetr, t_uint64 *map, int sq);
int				arrcmp(t_uint64 *arr1, t_uint64 *arr2, int arr_size);
void			sh_tet_nextline(t_fillit *fig, int sq);
void			remove_fig(t_fillit *fig, t_uint64 *map);
void			place_tetr_on_map(t_fillit *fig, t_uint64 *map);
void			fil_ch_lf(char *buf, int col_tetr, int sq);
void			print_map(t_fillit *tetr, int sq, int col_tetr);
t_uint64		mask_shift(int shift);
void			shift_bit_arr(t_uint64 *array, int arr_size, int shift);
void			shift_bit_arr_left(t_uint64 *array, int arr_size, int shift);
void			shift_bit_arr_right(t_uint64 *array, int arr_size, int shift);

#endif
