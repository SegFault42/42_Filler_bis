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

void	print_coord(int	y, int	x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	RC;
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
		if (ft_strstr(env->map[i], env->player) != NULL ||
			ft_strstr(env->map[i], env->player_min) != NULL)
		{
			if (env->player[0] == 'O')
			{
				env->rabougue = 3;
				env->ennemi = 6;
			}
			else if (env->player[0] == 'X')
			{
				env->rabougue = 6;
				env->ennemi = 3;
			}
			return (1);
		}
		else if (ft_strstr(env->map[i], "X") != NULL)
		{
			if (env->player[0] == 'O')
			{
				env->rabougue = 4;
				env->ennemi = 5;
			}
			else if (env->player[0] == 'X')
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

void	where_is_the_lower(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < env->size_map_y)
	{
		if (ft_strstr(env->map[y], env->player) != NULL ||
			ft_strstr(env->map[y], env->player_min) != NULL)
			env->last_y = y;
		++y;
	}
	while (x < env->size_map_x)
	{
		if (env->map[env->last_y][x] == ft_tolower(env->player[0]) ||
			env->map[env->last_y][x] == env->player[0])
			env->last_x = x;
		++x;
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
			if (env->map[env->last_y + y][env->last_x + x] != '.')
				return (EXIT_FAILURE);
			++x;
		}
		++y;
	}
	return (EXIT_SUCCESS);
}

void	split_map(t_env *env)
{
	where_is_the_lower(env);
	if (env->rabougue == 3)
		place_piece(env);
	else if (env->rabougue == 4 &&
	ft_strstr(env->map[env->size_map_y - 1], env->player) != NULL &&
	ft_strstr(env->map[0], env->player) != NULL)
	{
		count_empty_line_form_up(env);
		count_empty_line_form_down(env);
		env->size_form_y -= env->empty_line_form_down;
		/*[>[>uniquement pour carli<]<]*/
		/*if (ft_strstr(env->map[env->size_map_y - 1], "O") != NULL &&*/
			/*ft_strstr(env->map[0], "O") != NULL &&*/
			/*ft_strstr(env->map[0], "X") == NULL &&*/
			/*ft_strstr(env->map[env->size_map_y -1], "X") == NULL)*/
			/*fill_from_up_left(env);*/
		/*else*/
			fill_from_down_right(env);
	}
	else
		place_piece(env);
}

void	init_and_info_header(t_env *env, t_bonus *bonus, char *argv)
{
	init_filler_struct(env);
	init_bonus_struct(bonus);
	get_info_header(env, &argv);
	alloc_map(env);
}

void	sdl_bonus(t_win *win, t_env *env)
{
	win->loop = 1;
	init_window("Filler", env->size_map_x * 10, env->size_map_y * 10, win);
}

int	event()
{
	SDL_Event	event;

	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			return (-1);
		if (event.key.type == SDL_KEYDOWN)
			SDL_Delay(5000);
	}
	return (0);
}

void	draw_rect(SDL_Renderer *render, int width_x, int width_y, int pos_x, int pos_y)
{
	int x;
	int y;

	y = pos_y;
	while (y < width_y + pos_y)
	{
		x = pos_x;
		while (x < width_x + pos_x)
		{
			SDL_RenderDrawPoint(render, x, y);
			++x;
		}
		++y;
	}
}

void	draw(t_win *win, t_env *env)
{
	int	x;
	int	y;
	int	size_piece;

	size_piece = 10;
	y = 0;
	sdl_clear(win);
	while (y < env->size_map_y)
	{
		x = 0;
		while (x < env->size_map_x)
		{
			if (env->map[y][x] == '.')
			{
				SDL_SetRenderDrawColor(win->render, 100, 100, 100, 255);
				draw_rect(win->render, size_piece, size_piece, x * 10, y * 10);
			}
			else if (env->map[y][x] == 'X' || env->map[y][x] == 'x')
			{
				SDL_SetRenderDrawColor(win->render, 255, 0, 0, 255);
				draw_rect(win->render, size_piece, size_piece, x * 10, y * 10);
			}
			else if (env->map[y][x] == 'O' || env->map[y][x] == 'o')
			{
				SDL_SetRenderDrawColor(win->render, 0, 255, 0, 255);
				draw_rect(win->render, size_piece, size_piece, x * 10, y * 10);
			}
			++x;
		}
		++y;
	}
	SDL_RenderPresent(win->render);
}

void	filler_loop(t_env *env)
{
	get_map(env);
	if (env->rabougue < 2)
		check_who_is_higher(env);
	get_piece(env);
	split_map(env);
	re_init(env);
}

void	quit_filler(t_env *env, t_bonus *bonus, t_win *win)
{
	close_window(win);
	tab_free(env->piece, env->size_map_y);
	tab_free(env->map, env->size_map_y);
	free(env->player);
	free(env->other);
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_bonus	bonus;
	t_win	win;
	char	*line;

	init_and_info_header(&env, &bonus, argv[0]);
	sdl_bonus(&win, &env);
	while (win.loop)
	{
		while (get_next_line(STDIN_FILENO, &line) > 0)
		{
			if (event() == -1)
				break ;
			filler_loop(&env);
			free(line);
			draw(&win, &env);
		}
		win.loop = 0;
	}
	if (argc == 2)
		arguments(argv, &bonus, &env);
	quit_filler(&env, &bonus, &win);
}
