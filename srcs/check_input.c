/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:10:17 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/19 03:22:31 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

int		 	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	s1 = dest;
	s2 = (char*)src;
	while (i < n)
	{
		*s1 = *s2;
		s1++;
		s2 += (!*s2) ? 0 : 1;
		i++;
	}
	return (dest);
}

char		*input_arg(int argc, char **argv)
{
	int		fd;
	int		fr;
	char	*buf;

	fd = 0;
	buf = (char*)malloc(661 * sizeof(char));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 3)
		{
			write(1, "error file\n", 11);
			return (NULL);
		}
	}
	if (argc > 2)
	{
		printf("error fd");
		return (NULL);
	}
	fr = read(fd, buf, 660);
	if (fr < 0)
	{
		write(1, "error file\n", 11);
		return (NULL);
	}
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

/*
**	i = 0;
**	while (fig->tetr_char[i] != 0)
**		i++;
**	i--;
*/

void		conv_chtosh(t_fillit *fig)
{
	int		i;

	i = 19;
	while (--i >= 0)
	{
		if ((fig->tetr_char[i] == '#') || (fig->tetr_char[i] == '.'))
		{
			fig->tetr_bit <<= 1;
			if (fig->tetr_char[i] == '#')
				fig->tetr_bit |= 1;
		}
	}
}

void		conv_shtoarr(t_fillit *fig)
{
	(void)fig;
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

void		fil_struct(t_fillit *tetr, char *buf, int n_elem, int col_tetr)
{
	int			i;
	t_fillit	*fig;

	i = 4;
	fig = tetr + n_elem;
	while (i--)
		fig->tetr[i] = 0;
	fig->next = (n_elem == col_tetr - 1) ? tetr : (tetr + n_elem + 1);
	fig->prev = (n_elem == 0) ? (tetr + col_tetr - 1) : (tetr + n_elem - 1);
	fig->set = 0;
 	ft_strncpy(fig->tetr_char, &buf[n_elem * 21], 20);
	fig->tetr_char[20] = 0;
	fig->tetr_bit = 0;
	conv_chtosh(fig);
	sh_tl_bit(fig);
	search_width_tetr(fig);
	search_height_tetr(fig);
	conv_shtoarr(fig);
}

t_fillit	*create_mas(int argc, char **argv)
{
	t_fillit	*tetr;
	char		*buf;
	int			col_tetr;
	int			i;

	i = -1;
	buf = input_arg(argc, argv);
	if (!(check_buf(buf)))
		printf("exit");
	col_tetr = (ft_strlen(buf) + 1) / 21;
	tetr = (t_fillit*)malloc(sizeof(t_fillit) * col_tetr);
	while (++i < col_tetr)
		fil_struct(tetr, buf, i, col_tetr);
	free(buf);
	buf = NULL;
	return (tetr);
}

int			check_buf(char *buf)
{
	int	flag;

	flag = 0;
	if ((((ft_strlen(buf) + 1) % 21) == 0) && (buf[ft_strlen(buf)] == 0))
		flag = 1;
	return (flag);
}
