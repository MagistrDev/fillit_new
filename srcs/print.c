/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:22:12 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/22 20:37:31 by ecelsa           ###   ########.fr       */
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
	printf("---\n%s\n---\n",buf);
}

void	print_map(t_fillit *tetr, int sq)
{
	char			buf[300];
	int				col_tetr;
	int				i;
	int				n;
	int				n_elem;
	int				x;
	unsigned short	*sub;
	
	x = 0;
	n_elem = 0;
	col_tetr = tetr->prev - tetr + 1;
	buf[sq * (sq + 1)] = 0;
	
	while (n_elem < col_tetr)
	{
		n = 0;
		sub = (unsigned short*)((tetr + n_elem)->tetr);
		while (n < sq)
		{ 
			i = 0;
			while (i < sq)
			{
				if (!(i % (sq + 1)) && (i / (sq + 1)))
					x++;
				if (sub[n] & (1 << i))
					buf[(i + n * (sq )) + x] = 'A' + n_elem;
				i++;
			}
			n++;
		}
		n_elem++;
	}
	i = 0;
	while (i < sq * (sq + 1))
	{
		if (!(i % (sq + 1)) && (i / (sq + 1)))
			buf[i] = '\n';
		i++;
	}
	printf("%i ---\n%s\n---\n", sq * (sq + 1) + 1 , buf);
		
}
