/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:50:42 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/15 00:37:18 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# if __APPLE__ || __MACH__ || __linux__
# include <unistd.h>
# endif
# if __WINDOWS__
# include <io.h>
# endif
# include <stdlib.h>
# include <fcntl.h>

typedef unsigned long long		t_uint64;
typedef unsigned long long int	t_ulli;
typedef struct	s_fillit
{
	char			tetr_char[22];
	short			tetr_bit;
	t_uint64		tetr[4];
	int				set;
	struct s_fillit	*next;
	struct s_fillit	*prev;
}				t_fillit;

# include "check_input.h"
# include "shift_bits.h"
# include "place.h"

#endif
