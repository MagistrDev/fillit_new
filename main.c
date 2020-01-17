/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:50:02 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/17 20:38:08 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_fillit	*tetr;

	printf("start\n");
	tetr = create_mas(argc, argv);
	check_set(tetr);
	free(tetr);
	tetr = NULL;
	return (0);
}
