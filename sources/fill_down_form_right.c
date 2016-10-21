/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_from_down_right.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:21:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/23 22:19:24 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static int	calc_dist_left_and_last_o(t_env *env, t_ffdr *ffdr)
{
	int	x;
	int	y;

	x = ffdr->map_x;
	y = ffdr->map_y;
	while (env->map[y][x] != env->player[0])
		--x;
	return (x);
}

static void	init_ffdr(t_ffdr *ffdr, t_env *env)
{
	ffdr->piece_x = 0;
	ffdr->piece_y = 0;
	ffdr->map_x = env->size_map_x - env->size_form_x;
	ffdr->map_y = env->size_map_y - env->size_form_y;
	ffdr->me = 0;
	ffdr->ennemi = 0;
	ffdr->dist_left_and_last_o = calc_dist_left_and_last_o(env, ffdr);
}

static void	re_init_ffdr(t_env *env, t_ffdr *ffdr)
{
	ffdr->me = 0;
	ffdr->ennemi = 0;
	ffdr->piece_y = 0;
	ffdr->piece_x = 0;
	ffdr->map_x--;
	if (ft_strstr(env->map[env->size_map_y - 1], env->player) != NULL &&
		ft_strstr(env->map[0], env->player) != NULL)
	{
		if (ffdr->map_x + env->size_form_x < ffdr->dist_left_and_last_o)
		{
			ffdr->map_x = env->size_map_x - env->size_form_x;
			--ffdr->map_y;
			ffdr->dist_left_and_last_o = calc_dist_left_and_last_o(env, ffdr);
		}
		else
			--ffdr->map_x;
	}
	if (ffdr->map_x == -1)
	{
		ffdr->map_x = env->size_map_x - env->size_form_x;
		--ffdr->map_y;
	}
}

static int	fill_from_down_righ_2(t_env *env, t_ffdr *ffdr)
{
	++ffdr->piece_y;
	if (ffdr->piece_y == env->size_form_y)
	{
		if (ffdr->me == 1 && ffdr->ennemi == 0)
		{
			if (ffdr->map_y + (env->size_form_y - env->empty_line_form_up) <=
			env->size_map_y && ffdr->map_x +
			(env->size_form_x - env->empty_point_form_left) <= env->size_map_x)
			{
				if (ffdr->map_x < 0)
					fill_from_up_left(env);
				else
					print_coord(ffdr->map_y, ffdr->map_x);
				return (EXIT_SUCCESS);
			}
			else
			{
				print_coord(0, 0);
				return (EXIT_SUCCESS);
			}
		}
		else
			re_init_ffdr(env, ffdr);
	}
	return (EXIT_FAILURE);
}

void		fill_from_down_right(t_env *env)
{
	t_ffdr	ffdr;

	init_ffdr(&ffdr, env);
	while (ffdr.piece_y < env->size_form_y)
	{
		if (ffdr.map_y == 0)
		{
			fill_from_up_left(env);
			return ;
		}
		ffdr.piece_x = 0;
		while (ffdr.piece_x < env->size_form_x)
		{
			if ((env->map[DRPY + DRMY][DRPX + DRMX] == env->player_min[0] ||
			env->map[DRPY + DRMY][DRPX + DRMX] == env->player[0]) &&
			env->piece[DRPY][DRPX] == '*')
				ffdr.me++;
			else if (env->map[DRPY + DRMY][DRPX + DRMX] != '.' &&
			env->piece[DRPY][DRPX] == '*')
				ffdr.ennemi++;
			++ffdr.piece_x;
		}
		if (fill_from_down_righ_2(env, &ffdr) == EXIT_SUCCESS)
			return ;
	}
}
