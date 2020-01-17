/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ecelsa <ecelsa@school21.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:56:08 by Ecelsa            #+#    #+#             */
/*   Updated: 2020/01/16 14:56:08 by Ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
