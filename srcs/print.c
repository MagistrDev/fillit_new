/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:22:12 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/24 09:17:46 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tetr(t_fillit *tetr, int sq)
{
	int			i;
	t_fillit	ttt;

	i = 0;
	(void)tetr;
	(void)ttt;
	(void)sq;
	while (i < 256)
	{
		i++;
	}
}

void	test(t_uint64 *arr, int sq)
{
	unsigned short	*sub;
	char			buf[300];
	int				i;
	int				x;
	int				y;
	int				buf_i;

	(void)x;
	(void)sq;
	(void)sub;
	(void)arr;
	i = -1;
	while (++i < 300)
		buf[i] = '.';
	buf[sq * (sq + 1)] = 0;
	buf_i = 0;
	y = -1;
	while (++y < sq)
	{
		sub = (unsigned short*)((arr + y));
		x = 0;
		while (x <= sq)
		{
			if ((1 << x) & *sub)
				buf[buf_i] = 'A';
			if (x == sq)
				buf[buf_i] = '\n';
			x++;
			buf_i++;
		}
	}
//	printf("---\n%s\n---\n",buf);
}

void	print_map(t_fillit *tetr, int sq)
{
	char			buf[300];
	int				col_tetr;
	int				i;
	int				n;
	int				row;
	int				col;
	int				n_elem;
	int				x;
	int				num;
	unsigned short	*sub;

	(void)n;
	
	(void)sub;
	x = 0;
	n_elem = 0;
	col_tetr = tetr->prev - tetr + 1;
	ft_memset(buf, '.',sq * (sq + 1));
	buf[sq * (sq + 1)] = 0;
	i = 0;
	while (i++ <= col_tetr)
	{
		n = i*sq + i-1;
		buf[n] = '\n';
	}
	while (n_elem < col_tetr)
	{
		num = 0;
		row = 0;
		while (row < sq)
		{
			sub = (unsigned short*)(tetr + n_elem)->tetr;
 			col = 0;
 			while (col < sq)
			{
				if (*(sub + row) & (1 << col))
					buf[num + row] = 'A' + n_elem;
				num++;
				col++;
			}
			row++;
		}
		n_elem++;
	}
	ft_putstr(buf);
}

void		print_table(t_fillit *tetr, int sq)
{
	char			buf[300];
	int				col_tetr;

	ft_memset(buf, '.',300);
	(void)sq;
	(void)col_tetr;
	(void)tetr;
	printf("\n %s\n", buf);
}