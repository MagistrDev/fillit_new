/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:25:54 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/25 19:49:59 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*input_arg(int argc, char **argv)
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
	if (fd < 1)
		return (NULL);
	if ((fr = read(fd, buf, 660)) < 0 || fr > 546)
		return (NULL);
	close(fd);
	buf[fr] = 0;
	return (buf);
}

void	sh_tl_bit(t_fillit *fig)
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
	flag = 0;
	while (--i >= 0)
	{
		if (!((buf[i] == '#') || (buf[i] == '.') || (buf[i] == '\n')))
			break ;
		if (buf[i] == '#' || buf[i] == '.')
		{
			fig->tetr_bit <<= 1;
			if (buf[i] == '#')
			{
				fig->tetr_bit |= 1;
				flag++;
			}
		}
	}
	if (flag != 4)
		flag = 0;
	return (flag);
}

void	conv_shtoarr(t_fillit *fig)
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
