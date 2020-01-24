/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:22:12 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/25 00:07:17 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fil_ch_lf(char *buf, int col_tetr, int sq)
{
	int		n_elem;
	ft_memset(buf, 0, 299);
	ft_memset(buf, '.', sq * (sq + 1));
	buf[sq * (sq + 1) - 1] = 0;
	n_elem = 0;
	while (n_elem++ <= col_tetr + 1)
		buf[n_elem * sq + n_elem - 1] = '\n';
}

void	print_map(t_fillit *tetr, int sq, int col_tetr)
{
	char			buf[300];
	int				table[2];
	int				n_elem;
	int				num;
	unsigned short	*sub;

	fil_ch_lf(buf, col_tetr, sq);
	n_elem = -1;
	while (++n_elem < col_tetr)
	{
		num = 0;
		table[0] = -1;
		while (++table[0] < sq)
		{
			sub = (unsigned short*)(tetr + n_elem)->tetr;
			table[1] = -1;
			while (++table[1] < sq)
			{
				if (*(sub + table[0]) & (1 << table[1]))
					buf[num + table[0]] = 'A' + n_elem;
				num++;
			}
		}
	}
	ft_putstr(buf);
}
