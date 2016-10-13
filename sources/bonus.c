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

void	init_bonus_struct(t_bonus *bonus)
{
	bonus->x = -1;
	bonus->y = -1;
	bonus->nb_o = 0;
	bonus->nb_x = 0;
	bonus->nb_point = 0;
}

void	aff_percent_map(t_bonus *bonus)
{
	double	total;
	double	o;
	double	x;
	double	point;

	total = bonus->nb_o + bonus->nb_x + bonus->nb_point;
	o = total - bonus->nb_x - bonus->nb_point;
	x = total - bonus->nb_o - bonus->nb_point;
	point = total - bonus->nb_o - bonus->nb_x;
	ft_putendl_fd(PINK"-------------------------------------", 2);
	ft_putstr_fd(RED"Le joueur 1 a pris ", 2);
	fprintf(stderr, "%.2f", o * 100 / total);
	ft_putendl_fd("% de la map.", 2);
	ft_putstr_fd(ORANGE"Le joueur 2 a pris ", 2);
	fprintf(stderr, "%.2f", x * 100 / total);
	ft_putendl_fd("% de la map.", 2);
	fprintf(stderr, GREY"%.2f", point * 100 / total);
	ft_putendl_fd("% de la map n'a pas ete prise."END, 2);
	ft_putendl_fd(PINK"-------------------------------------"END, 2);
}

void	aff_map(t_env *env, t_bonus *bonus)
{
	while (bonus->y++ < env->size_map_y -1 && (bonus->x = -1))
	{
		while (bonus->x++ < env->size_map_x -1)
		{
			if (env->map[bonus->y][bonus->x] == 'O' || env->map[bonus->y][bonus->x] == 'o')
			{
				++bonus->nb_o;
				ft_putstr_fd(BRED"  ", 2);
			}
			else if (env->map[bonus->y][bonus->x] == 'X' || env->map[bonus->y][bonus->x] == 'x')
			{
				++bonus->nb_x;
				ft_putstr_fd(BORANGE"  ", 2);
			}
			else
			{
				++bonus->nb_point;
				ft_putstr_fd(BGREY"  ", 2);
			}
		}
		ft_putstr_fd(END"\n", 2);
	}
}
