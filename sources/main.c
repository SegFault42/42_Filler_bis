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
		if (ft_strstr(env->map[i], "O") != NULL)
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

/*void	count_empty_point_form_left(t_env *env)*/
/*{*/
	/*int	x = 0;*/
	/*int	y = 0;*/
	/*int	point = 0;*/

	/*while (y < env->size_form_y)*/
	/*{*/
		/*while (env->piece[y][x] == '.')*/
		/*{*/
			/*++point;*/
			/*++x;*/
		/*}*/
		/*if (point < env->empty_point_form_left)*/

		/*x = 0;*/
		/*++y;*/
	/*}*/
/*}*/

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
			/*if ((env->map[env->last_y][env->last_x] == 'o' || env->map[env->last_y][env->last_x] == 'O') && env->piece[y][x] == '*')*/
				/*me++;*/
			if (env->map[env->last_y][env->last_x + x] == 'x' || env->map[env->last_y + y][env->last_x + x] == 'X')
				ennemi++;
			++x;
		}
		++y;
	}
	//=========================================================================
	count_empty_line_form_up(env);
	if (((env->last_y + env->size_form_y) - env->empty_line_form_up) > env->size_map_y || (env->last_x + env->size_form_x) > env->size_map_x)
	{
		/*fill_from_up_right(env);*/
		sleep(10);
	}
	if (ennemi == 0)
		ft_fprintf(1, "%d %d\n", (env->last_y - substract_y), (env->last_x - substract_x));
}

void	split_map(t_env *env)
{
	if (env->rabougue == 3)
	{
		where_is_the_lower(env);
		place_piece(env);
	}
}

int	main(int argc, char **argv)
{
	t_env	env;
	char	*line;

	if (argc > 1)
		return (EXIT_FAILURE);
	init_filler_struct(&env);
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
	tab_free(env.piece, env.size_form_y);
	tab_free(env.map, env.size_map_y);
	/*sleep(10);*/
}
