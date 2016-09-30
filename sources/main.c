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
			++env->len_piece_ver;
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
				if (tmp > env->len_piece_hor)
					env->len_piece_hor = tmp;
				++j;
			}
		tmp = 0;
		++i;
	}
}

int	check_start_position(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->size_map_y)
	{
		if (ft_strstr(env->map[i], "O") != NULL)
		{
			if (i <= env->size_map_y / 2)
			{
				env->pos_p1 = 1;
				env->pos_p2 = 2;
				return (1);
			}
			else
			{
				env->pos_p1 = 2;
				env->pos_p2 = 1;
				return (1);
			}
		}
		++i;
	}
	return (-1);
}

void	resolv(t_env *env)
{
	if (env->start == 0)
		env->start = check_start_position(env);
	if (env->start == 1)
	{
		
	}
	len_piece_xy(env);
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
		get_piece(&env);
		resolv(&env);
		re_init(&env);
		free(line);
		tab_free(env.piece, env.size_form_y);
	}
	tab_free(env.map, env.size_map_y);
	/*sleep(10);*/
}
