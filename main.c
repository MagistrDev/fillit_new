/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:50:02 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/18 22:56:13 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_fillit	*tetr;
	t_uint64	map[4];
	int			i;

	printf("start\n");
	i = 4;
	while (i--)
		map[i] = 0;
	tetr = create_mas(argc, argv);
	place_tetr(tetr, map, 4);
	place_tetr(tetr + 1, map, 4);
	place_tetr(tetr + 2, map, 4);
	place_tetr(tetr + 3, map, 4);
	place_tetr(tetr + 4, map, 4);
	free(tetr);
	tetr = NULL;
	return (0);
}
