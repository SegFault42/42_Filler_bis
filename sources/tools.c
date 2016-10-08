/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 01:02:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/23 21:53:50 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	alloc_map(t_env *env)
{
	int	i;

	i = 0;
	get_size_map(env);
	env->map = (char **)malloc(sizeof(char *) * env->size_map_y);
	env->piece = (char **)malloc(sizeof(char *) * env->size_map_y);
	while (i < env->size_map_y)
	{
		env->map[i] = ft_memalloc(env->size_map_x + 1);
		env->piece[i] = ft_memalloc(env->size_map_x + 1);
		++i;
	}
}

void	init_filler_struct(t_env *env)
{
	env->map = NULL;
	env->piece = NULL;
	env->rabougue = -1;
	env->ennemi = -1;
	env->size_map_y = 0;
	env->size_map_x = 0;
	env->step = 0;
	env->size_form_y = 0;
	env->size_form_x = 0;
	env->len_piece_hor = 0;
	env->len_piece_ver = 0;
	env->pos_p1 = 0;
	env->pos_p2 = 0;
	env->start = 0;
}

void	re_init(t_env *env)
{
	int	i;

	i = 0;
	env->len_piece_hor = 0;
	env->len_piece_ver = 0;
	while (i < env->size_form_y)
	{
		ft_memset(env->piece[i], 0, env->size_form_x);
		++i;
	}
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
