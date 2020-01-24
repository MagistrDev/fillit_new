/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:22:12 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/24 18:45:10 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fil_ch_lf(char *buf, int col_tetr, int sq)
{
	int		n_elem;

	n_elem = 0;
	while (n_elem++ <= col_tetr)
		buf[n_elem * sq + n_elem - 1] = '\n';
}

void	print_map(t_fillit *tetr, int sq)
{
	char			buf[300];
	int				col_tetr;
	int				row;
	int				col;
	int				n_elem;
	int				num;
	unsigned short	*sub;

	ft_memset(buf, '.',sq * (sq + 1));
	buf[sq * (sq + 1)] = 0;
	col_tetr = tetr->prev - tetr + 1;
	fil_ch_lf(buf, col_tetr, sq);
	n_elem = -1;
	while (++n_elem < col_tetr)
	{
		num = 0;
		row = -1;
		while (++row < sq)
		{
			sub = (unsigned short*)(tetr + n_elem)->tetr;
 			col = -1;
 			while (++col < sq)
			{
				if (*(sub + row) & (1 << col))
					buf[num + row] = 'A' + n_elem;
				num++;
			}
		}
	}
	ft_putstr(buf);
}
