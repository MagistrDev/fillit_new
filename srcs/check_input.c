/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:10:17 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/24 23:54:36 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern const short		g_valid[];

char		*input_arg(int argc, char **argv)
{
	int		fd;
	int		fr;
	char	*buf;

	fd = 0;
	if (argc != 2)
		return (NULL);
	if (!(buf = (char*)malloc(661 * sizeof(char))))
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return (NULL);
	if ((fr = read(fd, buf, 660)) < 0)
		return (NULL);
	if (fd > 2)
		close(fd);
	buf[fr] = 0;
	return (buf);
}

void		sh_tl_bit(t_fillit *fig)
{
	if (!(fig->tetr_bit))
		return ;
	while (!(fig->tetr_bit & 0xf))
		fig->tetr_bit >>= 4;
	while (!(fig->tetr_bit & 0x1111))
		fig->tetr_bit >>= 1;
}

int		conv_chtosh(t_fillit *fig)
{
	int		i;
	int		flag;
	char	*buf;

	buf = fig->tetr_char;
	i = 20;
	while (--i >= 0)
	{
		flag = 1;
		if ((buf[i] == '#') || (buf[i] == '.') || (buf[i] == '\n'))
		{
			if (buf[i] == '#' || buf[i] == '.')
			{
				fig->tetr_bit <<= 1;
				if (buf[i] == '#')
					fig->tetr_bit |= 1;
			}
		}
		else
		{
			flag = 0;
			break ;
		}
	}
	return (flag);
}

void		conv_shtoarr(t_fillit *fig)
{
	fig->tetr[0] = 0;
	fig->tetr[1] = 0;
	fig->tetr[2] = 0;
	fig->tetr[3] = 0;
	fig->tetr[0] = (fig->tetr_bit & 0xf000);
	fig->tetr[0] <<= 12;
	fig->tetr[0] |= (fig->tetr_bit & 0xf00);
	fig->tetr[0] <<= 12;
	fig->tetr[0] |= (fig->tetr_bit & 0xf0);
	fig->tetr[0] <<= 12;
	fig->tetr[0] |= (fig->tetr_bit & 0xf);
}

void		search_height_tetr(t_fillit *fig)
{
	int		height_tetr;
	short	bit;

	bit = fig->tetr_bit;
	height_tetr = 0;
	while (bit & 0xf)
	{
		height_tetr++;
		bit >>= 4;
	}
	fig->height_tetr = height_tetr;
}

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

int		valid_tet(t_fillit *tetr, int col_tetr)
{
	int		i;
	int		n;
	int		flag;

	n = -1;
	while (++n < col_tetr)
	{
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