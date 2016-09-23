/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:21:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/23 02:38:33 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	alloc_map_and_piece(t_env *env)
{
	int	i;

	i = 0;
	get_size_map(env);
	env->map = (char **)malloc(sizeof(char *) * env->size_map_y);
	while (i < env->size_map_y)
	{
		env->map[i] = ft_memalloc(env->size_map_x + 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_env	env;
	char	*line;
	int i, j;

	if (argc > 1)
		return (EXIT_FAILURE);
	init_struct(&env);
	get_info_header(&env, &argv[0]);
	alloc_map_and_piece(&env);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		i = 0;
		j = 0;
		/*if (env.step == 0)*/
			get_map(&env);
		/*if (env.step == 1)*/
			get_piece(&env);
		while (i < env.size_map_y)
		{
			printf(YELLOW"%s\n"END, env.map[i]);
			++i;
		}
		while (j < env.size_piece_y)
		{
			printf(CYAN"%s\n"END, env.piece[j]);
			++j;
		}
		free(line);
	tab_free(env.piece, env.size_piece_y);
	}
	tab_free(env.map, env.size_map_y);
	sleep(10);
}
