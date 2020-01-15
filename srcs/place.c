/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:09:03 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/15 03:24:27 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	border_right(t_uint64 *arr, int sq)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		*(arr + i) |= ft_mask_shift(16 - sq); 
		*(arr + i) <<= 16;
		*(arr + i) |= ft_mask_shift(16 - sq);
		*(arr + i) <<= 16;
		*(arr + i) |= ft_mask_shift(16 - sq);
		*(arr + i) <<= 16;
		*(arr + i) |= ft_mask_shift(16 - sq);
	}
}

int		check_set(t_fillit *tetr)
{
	int			flag;
	int			col_tetr;
	int			i;
	int			sq;
	t_uint64	b_r[4];
	t_uint64	b_b[4];
			
	sq = 4;
	i = -1;
	border_right(b_r, sq);
	border_right(b_b, sq);
	col_tetr = (tetr->prev - tetr) + 1;
	flag = 1;
	while (++i < col_tetr)
		flag = (!((tetr + i)->set)) ? 0 : 1;
	return (flag);
}

void	place_tetr(t_fillit *tetr)
{
	while (!(check_set(tetr)))
	{
		
	}
	(void)tetr;
	
}