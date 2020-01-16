/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ecelsa <ecelsa@school21.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:50:02 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/16 12:24:42 by Ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_fillit	*tetr;

	printf("start\n");
	tetr = create_mas(argc, argv);
	(void)tetr;
//	place_tetr(tetr);
	check_set(tetr);
	free(tetr);
	tetr = NULL;	
	return  (0);
	
}
