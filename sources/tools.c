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
	env->size_piece_x = 0;
	env->size_piece_y = 0;
	env->start = 0;
	env->last_x = 0;
	env->last_y = 0;
	env->empty_line_form_up = 0;
	env->empty_line_form_down = 0;
	env->empty_point_form_left = 0;
	env->player = 0;
	env->other = 0;
}

void	re_init(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->size_form_y)
	{
		ft_memset(env->piece[i], 0, env->size_form_x);
		++i;
	}
	env->size_form_y = 0;
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

void	who_is_x_or_o(t_env *env)
{
	if (env->rabougue == 1)
		env->player = 'O';
	else
		env->player = 'X';
}
