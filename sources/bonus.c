/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:43:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/17 06:31:28 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static void	calc_map(t_env *env, t_bonus *bonus)
{
	while (bonus->y++ < env->size_map_y -1 && (bonus->x = -1))
		while (bonus->x++ < env->size_map_x -1)
		{
			if (env->map[bonus->y][bonus->x] == 'O' ||
			env->map[bonus->y][bonus->x] == 'o')
				++bonus->nb_o;
			else if (env->map[bonus->y][bonus->x] == 'X' ||
			env->map[bonus->y][bonus->x] == 'x')
				++bonus->nb_x;
			else
				++bonus->nb_point;
		}
}

void	aff_percent_map(t_bonus *bonus, t_env *env)
{
	double	total;
	double	o;
	double	x;
	double	point;

	init_bonus_struct(bonus);
	calc_map(env, bonus);
	total = bonus->nb_o + bonus->nb_x + bonus->nb_point;
	o = total - bonus->nb_x - bonus->nb_point;
	x = total - bonus->nb_o - bonus->nb_point;
	point = total - bonus->nb_o - bonus->nb_x;
	ft_putendl_fd(PINK"-------------------------------------", 2);
	ft_putstr_fd(GREEN"Le joueur 1 a pris ", 2);
	fprintf(stderr, "%.2f", o * 100 / total);
	ft_putendl_fd("% de la map.", 2);
	ft_putstr_fd(PURPLE"Le joueur 2 a pris ", 2);
	fprintf(stderr, "%.2f", x * 100 / total);
	ft_putendl_fd("% de la map.", 2);
	fprintf(stderr, GREY"%.2f", point * 100 / total);
	ft_putendl_fd("% de la map n'a pas ete pris."END, 2);
	ft_putendl_fd(PINK"-------------------------------------"END, 2);
}

static void	count_and_color_map(t_bonus *bonus, t_env *env)
{
	if (env->map[bonus->y][bonus->x] == 'O' || env->map[bonus->y][bonus->x] == 'o')
	{
		ft_putstr_fd(BGREEN" ", 2);
		++bonus->nb_o;
	}
	else if (env->map[bonus->y][bonus->x] == 'X' || env->map[bonus->y][bonus->x] == 'x')
	{
		++bonus->nb_x;
		ft_putstr_fd(BPURPLE" ", 2);
	}
	else if (env->map[bonus->y][bonus->x] != '.')
	{
		++bonus->nb_point;
		ft_putstr_fd(BWHITE" ", 2);
	}
	else
	{
		++bonus->nb_point;
		ft_putstr_fd(BGREY" ", 2);
	}
}

void	aff_map(t_env *env, t_bonus *bonus)
{
	while (bonus->y++ < env->size_map_y -1 && (bonus->x = -1))
	{
		while (bonus->x++ < env->size_map_x -1)
			count_and_color_map(bonus, env);
		ft_putstr_fd(END"\n", 2);
	}
}

void	arguments(char **argv, t_bonus *bonus, t_env *env)
{
	if (argv[1][0] == '-')
	{
		if (ft_strstr(argv[1], "m") != NULL)
			aff_map(env, bonus);
		if (ft_strstr(argv[1], "p") != NULL)
			aff_percent_map(bonus, env);
	}
}
