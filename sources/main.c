/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:21:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/23 05:01:37 by rabougue         ###   ########.fr       */
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
			++env->len_piece_y;
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
				if (tmp > env->len_piece_x)
					env->len_piece_x = tmp;
				++j;
			}
		tmp = 0;
		++i;
	}
}

void	resolv(t_env *env)
{
	len_piece_xy(env);
}

int	main(int argc, char **argv)
{
	t_env	env;
	char	*line;

	if (argc > 1)
		return (EXIT_FAILURE);
	init_struct(&env);
	get_info_header(&env, &argv[0]);
	alloc_map(&env);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		/*if (env.step == 0)*/
		get_map(&env);
		/*if (env.step == 1)*/
		get_piece(&env);
		resolv(&env);
		printf("y = %d - ", env.len_piece_y);
		printf("x = %d\n", env.len_piece_x);
		re_init(&env);
		free(line);
		tab_free(env.piece, env.size_form_y);
	}
	tab_free(env.map, env.size_map_y);
	/*sleep(10);*/
}
