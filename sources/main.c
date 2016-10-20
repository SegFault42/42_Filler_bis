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

void	print_coord(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	RC;
}

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

void	quit_filler(t_env *env, t_win *win, char *argv)
{
	close_window(win);
	if (argv != NULL && ft_strstr(argv, "s") != NULL)
	{
		Mix_FreeMusic(win->music);
		Mix_CloseAudio();
	}
	tab_free(env->piece, env->size_map_y);
	tab_free(env->map, env->size_map_y);
	free(env->player);
	free(env->other);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_bonus	bonus;
	t_win	win;
	char	*line;

	if (argc > 2)
		exit(-1);
	init_and_info_header(&env, &bonus, argv[0]);
	sdl_init(&win, &env, argv[1]);
	while (win.loop)
	{
		while (get_next_line(STDIN_FILENO, &line) > 0)
		{
			if (event(&env, &win, argv[1]) == -1)
				exit(-1);
			filler_loop(&env);
			free(line);
			draw(&win, &env);
			re_init(&env);
		}
		win.loop = 0;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Filler by Rabougue", "Game finished.", win.win);
	}
	if (argc == 2)
		arguments(argv, &bonus, &env);
	while(0xDEADBEEF)
		if (event(&env, &win, argv[1]) == -2)
			break ;
	quit_filler(&env, &win, argv[1]);
}
