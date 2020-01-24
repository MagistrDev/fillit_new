/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:10:17 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/25 01:18:03 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern const short		g_valid[];

void		search_width_tetr(t_fillit *fig)
{
	short	bit;
	int		width_tetr;

	bit = fig->tetr_bit;
	width_tetr = 0;
	bit |= (bit >> 4) | (bit >> 8) | (bit >> 12);
	bit &= 0xf;
	while (bit & 1)
	{
		bit >>= 1;
		width_tetr++;
	}
	fig->width_tetr = width_tetr;
}

int			fil_struct(t_fillit *tetr, char *buf, int n_elem, int col_tetr)
{
	t_fillit	*fig;

	fig = tetr + n_elem;
	ft_bzero(fig->tetr_char, 22);
	ft_bzero(fig->tetr, 32);
	fig->next = (n_elem == col_tetr - 1) ? tetr : (tetr + n_elem + 1);
	fig->prev = (n_elem == 0) ? (tetr + col_tetr - 1) : (tetr + n_elem - 1);
	fig->set = 0;
	ft_strncpy(fig->tetr_char, &buf[n_elem * 21], 21);
	fig->tetr_bit = 0;
	if (!conv_chtosh(fig))
		return (0);
	sh_tl_bit(fig);
	search_width_tetr(fig);
	search_height_tetr(fig);
	conv_shtoarr(fig);
	return (1);
}

t_fillit	*create_mas(int argc, char **argv)
{
	t_fillit	*tetr;
	char		*buf;
	int			col_tetr;
	int			i;

	i = -1;
	if (!(buf = input_arg(argc, argv)))
		return (NULL);
	if (!check_buf(buf))
	{
		free(buf);
		return (NULL);
	}
	col_tetr = (ft_strlen(buf) + 1) / 21;
	if (!(tetr = (t_fillit*)malloc(sizeof(t_fillit) * col_tetr)))
	{
		free(buf);
		return (NULL);
	}
	while (++i < col_tetr)
		if (!fil_struct(tetr, buf, i, col_tetr))
			return (NULL);
	free(buf);
	buf = NULL;
	return (tetr);
}

int			check_buf(char *buf)
{
	int		flag;

	if (!((((ft_strlen(buf) + 1) % 21) == 0) && (buf[ft_strlen(buf)] == 0)))
		flag = 0;
	else
		flag = 1;
	return (flag);
}


int col_lf(char *str)
{
	int i;
	int col;

	col = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			col++;
		i++;
	}
	return (col);
}

int			valid_tet(t_fillit *tetr, int col_tetr)
{
	int		i;
	int		n;
	int		flag;

	n = -1;
	while (++n < col_tetr)
	{
		if (!((((tetr + n) == tetr->prev) & (col_lf((tetr + n)->tetr_char) == 4))
			|| (((tetr + n) != tetr->prev) &
			(col_lf((tetr + n)->tetr_char) == 5))))
			return (0);
		flag = 0;
		i = -1;
		while (++i < 19)
			if ((tetr + n)->tetr_bit == g_valid[i])
				flag = 1;
		if (!flag)
			return (0);		
	}
	return (flag);
}
