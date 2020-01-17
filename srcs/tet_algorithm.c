/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:19:00 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/17 20:32:48 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_tetcmp(t_ulli *table, t_uint64 *tetr, int sq)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	(void)sq;
	while (i < 4)
	{
		if (table[i] & tetr[i])
			r |= 1;
		i++;
	}
	return (r);
}
