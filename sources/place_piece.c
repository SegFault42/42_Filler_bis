/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:21:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/23 22:19:24 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static int	close_up(t_env *env)
{
	if ((ft_strstr(env->map[0], env->player) == NULL && env->size_map_y == 15)
	|| (ft_strstr(env->map[0], env->player) == NULL && env->size_map_y == 100))
	{
		fill_from_up_left(env);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static int	vertical_line_ok(t_env *env)
{
	if (ft_strstr(env->map[env->size_map_y - 1], env->player) != NULL &&
		ft_strstr(env->map[0], env->player) != NULL)
	{
		fill_from_down_right(env);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static int	if_cross_ennemi(t_env *env)
{
	if ((ft_strstr(env->map[env->size_map_y - 1], env->player) == NULL ||
		ft_strstr(env->map[0], env->player) == NULL) &&
		check_if_ennemi(env) == EXIT_FAILURE)
	{
		if (ft_strstr(env->map[env->size_map_y - 1], env->player) == NULL)
		{
			fill_from_down_right(env);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

static int	no_name(t_env *env, int substract_y, int substract_x)
{
	if (((env->last_y + env->size_form_y) - env->empty_line_form_up) >
	env->size_map_y || (env->last_x + env->size_form_x) > env->size_map_x)
	{
		fill_from_up_left(env);
		return (EXIT_SUCCESS);
	}
	if (check_if_ennemi(env) == EXIT_FAILURE)
	{
		fill_from_up_left(env);
		return (EXIT_SUCCESS);
	}
	print_coord(env->last_y - substract_y, env->last_x - substract_x);
	return (EXIT_SUCCESS);
}

void		place_piece(t_env *env)
{
	int	substract_y;
	int	substract_x;

	substract_y = 0;
	substract_x = 0;
	substract_x_y(&substract_x, &substract_y, env);
	count_empty_line_form_up(env);
	count_empty_line_form_down(env);
	env->size_form_y -= env->empty_line_form_down;
	count_empty_point_form_left(env);
	if (close_up(env) == EXIT_SUCCESS)
		return ;
	if (vertical_line_ok(env) == EXIT_SUCCESS)
		return ;
	if (if_cross_ennemi(env) == EXIT_SUCCESS)
		return ;
	no_name(env, substract_y, substract_x);
}
