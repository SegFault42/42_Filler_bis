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

void	init_and_info_header(t_env *env, t_bonus *bonus, char *argv)
{
	init_filler_struct(env);
	init_bonus_struct(bonus);
	get_info_header(env, &argv);
	alloc_map(env);
}

void	filler_loop(t_env *env)
{
	get_map(env);
	if (env->rabougue < 2)
		check_who_is_higher(env);
	get_piece(env);
	split_map(env);
}

void	quit_filler(t_env *env, t_win *win)
{
	if (env->b_graphic == 1)
	{
		close_window(win);
		Mix_FreeChunk(win->chunk);
	}
	if (env->b_sound == 1)
		Mix_FreeMusic(win->music);
	Mix_CloseAudio();
	tab_free(env->piece, env->size_map_y);
	tab_free(env->map, env->size_map_y);
	free(env->player);
	free(env->other);
	exit(EXIT_SUCCESS);
}

int		main_loop(t_win *win, t_env *env, t_bonus *bonus)
{
	char	*line;

	line = NULL;
	win->loop = 1;
	while (win->loop)
	{
		while (get_next_line(STDIN_FILENO, &line) > 0)
		{
			if (env->b_graphic == 1)
				event(env, win, bonus);
			filler_loop(env);
			free(line);
			if (env->b_graphic == 1)
				draw(win, env);
			re_init(env);
		}
		win->loop = 0;
		if (env->b_graphic == 1)
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
			"Filler by Rabougue", "Game finished.", win->win);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;
	t_bonus	bonus;
	t_win	win;

	init_and_info_header(&env, &bonus, argv[0]);
	init_bonus_arg(&env, argv);
	if (env.b_graphic == 1)
		sdl_init(&win, &env);
	main_loop(&win, &env, &bonus);
	if (argc == 2)
		arguments(argv, &bonus, &env);
	if (env.b_graphic == 1)
	{
		while (0xDEADBEEF)
			if (event(&env, &win, &bonus) == -2)
				break ;
	}
	quit_filler(&env, &win);
}
