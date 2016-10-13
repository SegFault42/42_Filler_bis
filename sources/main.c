/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:21:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/23 22:19:24 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	len_piece_xy(t_env *env)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while(i < env->size_form_y)
	{
		if (ft_strstr(env->piece[i], "*") != NULL)
			++env->size_piece_y;
		++i;
	}
	i = 0;
	while (i < env->size_form_y)
	{
		j = 0;
		if (ft_strstr(env->piece[i], "*") != NULL)
			while (j < env->size_form_x)
			{
				if (env->piece[i][j] == '*')
					++tmp;
				if (tmp > env->size_piece_x)
					env->size_piece_x = tmp;
				++j;
			}
		tmp = 0;
		++i;
	}
}
/*=============================================================================
** Check who is higher and who is first player. See filler.h for more info.
*/
int	check_who_is_higher(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->size_map_y)
	{
		if (ft_strstr(env->map[i], "O") != NULL || ft_strstr(env->map[i], "o") != NULL)
		{
			if (env->rabougue == 1)
			{
				env->rabougue = 3;
				env->ennemi = 6;
			}
			else if (env->rabougue == 2)
			{
				env->rabougue = 6;
				env->ennemi = 3;
			}
			return (1);
		}
		else if (ft_strstr(env->map[i], "X") != NULL)
		{
			if (env->rabougue == 1)
			{
				env->rabougue = 4;
				env->ennemi = 5;
			}
			else if (env->rabougue == 2)
			{
				env->rabougue = 5;
				env->ennemi = 4;
			}
			return (1);
		}
		++i;
	}
	return (-1);
}
/*
**=============================================================================
*/

/*int		check_if_piece_ok(t_env *env, int *map_y, int *map_x)*/
/*{*/
	/*int	p_x = 0, p_y = 0;*/
	/*int	tmp_map_y = *map_y, tmp_map_x = *map_x;*/

	/*while (p_y < env->size_piece_y)*/
	/*{*/
		/*while (p_x < env->size_piece_x)*/
		/*{*/
			/*while (env->piece[p_y][p_x] != '*')*/
			/*{*/
				/*if (p_x > env->size_piece_x)*/
					/*break;*/
				/*++p_x;*/
				/*++*map_x;*/
			/*}*/
			/*if (env->piece[p_y][p_x] == '*')*/
		/*}*/
	/*}*/
	/*(void)map_x;*/
	/*return (EXIT_FAILURE);*/
/*}*/

void	where_is_the_lower(t_env *env)
{
	int x = 0, y = 0;

	while (y < env->size_map_y)
	{
		if (ft_strstr(env->map[y], "O") != NULL || ft_strstr(env->map[y], "o") != NULL)
			env->last_y = y;
		++y;
	}
	while (x < env->size_map_x)
	{
		if (env->map[env->last_y][x] == 'o' || env->map[env->last_y][x] == 'O')
			env->last_x = x;
		++x;
	}
}

void	count_empty_line_form_up(t_env *env)
{
	int	i = 0;

	while (ft_strstr(env->piece[i], "*") == NULL)
		i++;
	env->empty_line_form_up = i;
}

void	count_empty_point_form_left(t_env *env)
{
	int	x = 0;
	int	y = 0;
	int	point = 0;

	env->empty_point_form_left = env->size_form_x;
	while (y < env->size_form_y)
	{
		while (env->piece[y][x] == '.')
		{
			++point;
			++x;
		}
		if (point < env->empty_point_form_left)
			env->empty_point_form_left = point;
		point = 0;
		x = 0;
		++y;
	}
}

int	check_if_ennemi(t_env *env)
{
	int	x = 0;
	int	y = 0;

	if (env->last_y + env->size_form_y > env->size_map_y)
		return (EXIT_FAILURE);
	while (y < env->size_form_y)
	{
		x = 0;
		while (x < env->size_form_x)
		{
			if (env->map[env->last_y + y][env->last_x + x] == 'x' ||
				env->map[env->last_y + y][env->last_x + x] == 'X')
				return (EXIT_FAILURE);
			++x;
		}
		++y;
	}
	return (EXIT_SUCCESS);
}

void	place_piece(t_env *env)
{
	int	x = 0, y = 0;
	/*int	me = 0;*/
	int	ennemi = 0;
	int	substract_y = 0;
	int	substract_x = 0;

	while (ft_strstr(env->piece[y], "*") == NULL)
	{
		++y;
		++substract_y;
	}
	while (env->piece[y][x] != '*')
	{
		++x;
		++substract_x;
	}
	//=========================================================================
	while (y < env->size_piece_y)
	{
		x = 0;
		while (x < env->size_piece_x)
		{
			/*if ((env->map[env->last_y][env->last_x] == 'o' ||
			 * env->map[env->last_y][env->last_x] == 'O') && env->piece[y][x] == '*')*/
				/*me++;*/
			if (env->map[env->last_y][env->last_x + x] == 'x' ||
			env->map[env->last_y + y][env->last_x + x] == 'X')
				ennemi++;
			++x;
		}
		++y;
	}
	count_empty_line_form_up(env);
	/*count_empty_point_form_left(env);*/
	/*if (ft_strstr(env->map[env->size_map_y], "O") != NULL && ft_strstr(env->map[0], "O") != NULL)*/
	/*{*/
		/*fill_from_up_left(env);*/
	/*}*/
	//=========================================================================
	//pour fermer au dessus en premier
	if (ft_strstr(env->map[0], "O") == NULL)
	{
		fill_from_up_left(env);
		/*ft_putnbr(env->last_y - substract_y);*/
		/*ft_putchar(' ');*/
		/*ft_putnbr((substract_x - env->last_x) - env->empty_point_form_left -1 );*/
		/*RC;*/
		return ;
	}
	//=========================================================================
	//=========================================================================
	//pour stopper une fois qu'un trait vertical est tracer
		if (ft_strstr(env->map[env->size_map_y - 1], "O") != NULL && ft_strstr(env->map[0], "O") != NULL)
		{
			/*sleep(1);*/
			fill_from_up_left(env);
			/*fill_from_down_right(env);*/
			return ;
		}
	//=========================================================================
	//=========================================================================
	//pour fermer la map en bas si je percute l'adverssaire avant de fermer.
	if ((ft_strstr(env->map[env->size_map_y - 1], "O") == NULL || ft_strstr(env->map[0], "O") == NULL) && check_if_ennemi(env) == EXIT_FAILURE)
	{
		if (ft_strstr(env->map[env->size_map_y - 1], "O") == NULL)
		{
			fill_from_down_right(env);
			return ;
		}
	}
	//=========================================================================
	if (((env->last_y + env->size_form_y) - env->empty_line_form_up) > env->size_map_y ||
	(env->last_x + env->size_form_x) > env->size_map_x )
	{
		fill_from_up_left(env);
		return ;
	}
	else if (ennemi == 0 /*&& (ft_strstr(env->map[env->size_map_y - 1], "O") == NULL || ft_strstr(env->map[0], "O") == NULL)*/)
	{
		if (check_if_ennemi(env) == EXIT_FAILURE)
		{
			fill_from_up_left(env);
			return ;
		}
		ft_fprintf(1, "%d %d\n", (env->last_y - substract_y), (env->last_x - substract_x));
		return ;
	}
	else
	{
		/*sleep(10);*/
		ft_fprintf(1, "0 0\n");
		return ;
	}
}

void	split_map(t_env *env)
{
	if (env->rabougue == 3 /*4*/)
	{
		where_is_the_lower(env);
		place_piece(env);
	}
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_bonus	bonus;
	char	*line;

	if (argc > 1)
		return (EXIT_FAILURE);
	init_filler_struct(&env);
	init_bonus_struct(&bonus);
	get_info_header(&env, &argv[0]);
	alloc_map(&env);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		get_map(&env);
		if (env.rabougue < 2)
			check_who_is_higher(&env);
		/*ft_print_2d_tab(env.map, env.size_map_y);*/
		get_piece(&env);
		/*ft_print_2d_tab(env.piece, env.size_form_y);*/
		split_map(&env);
		/*resolv(&env);*/
		re_init(&env);
		free(line);
	}
	aff_map(&env, &bonus);
	aff_percent_map(&bonus);
	tab_free(env.piece, env.size_map_y);
	tab_free(env.map, env.size_map_y);
}
