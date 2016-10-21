/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:21:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/23 22:19:24 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	count_empty_line_form_up(t_env *env)
{
	int	i;

	i = 0;
	while (ft_strstr(env->piece[i], "*") == NULL)
		i++;
	env->empty_line_form_up = i;
}

void	count_empty_line_form_down(t_env *env)
{
	int	i;
	int	j;

	i = env->size_form_y - 1;
	j = 0;
	while (ft_strstr(env->piece[i], "*") == NULL)
	{
		i--;
		j++;
	}
	env->empty_line_form_down = j;
}

void	count_empty_point_form_left(t_env *env)
{
	int	x;
	int	y;
	int	point;

	y = 0;
	point = 0;
	env->empty_point_form_left = env->size_form_x;
	while (y < env->size_form_y)
	{
		x = 0;
		while (env->piece[y][x] == '.')
		{
			++point;
			++x;
		}
		if (point < env->empty_point_form_left)
			env->empty_point_form_left = point;
		point = 0;
		++y;
	}
}
