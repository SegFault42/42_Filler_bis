/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 01:02:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/22 03:19:23 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	init_struct(t_env *env)
{
	env->map = NULL;
	env->piece = NULL;
	env->rabougue = -1;
	env->ennemi = -1;
	env->size_map_y = 0;
	env->size_map_x = 0;
	env->step = 0;
	env->size_piece_y = 0;
	env->size_piece_x = 0;
}

void	tab_free(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}
