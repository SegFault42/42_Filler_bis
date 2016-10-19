#include "../include/filler.h"

static void	draw_square(SDL_Renderer *render, int width_x, int width_y, int pos_x, int pos_y)
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

static void	draw_grille(t_env *env, t_win *win, int	map_x, int map_y)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	SDL_SetRenderDrawColor(win->render, 0, 0, 0, 255);
	while (y < map_y)
	{
		SDL_RenderDrawLine(win->render, 0, y, map_x, y);
		y += win->size_plateau;
	}
	while (x < map_x)
	{
		SDL_RenderDrawLine(win->render, x, 0, x, map_y);
		x += win->size_plateau;
	}
}


void	sdl_init(t_win *win, t_env *env)
{
	win->police = TTF_OpenFont("./fonts/No more lies.ttf", 16);
	win->loop = 1;
	win->size_plateau = 10;
	win->size_piece = 10;
	init_window("Filler by Rabougue", (env->size_map_x * 2) * win->size_plateau,
						  env->size_map_y * win->size_plateau, win);
	if(TTF_Init() == -1)
	{
		ft_fprintf(2, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
}

int	event()
{
	SDL_Event	event;

	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit (-1);
		if (event.key.keysym.sym == SDLK_ESCAPE)
			exit (-2);
		if (event.key.type == SDL_KEYDOWN && event.key.repeat == 0)
			if (event.key.keysym.sym == SDLK_SPACE)
				SDL_Delay(2000);
	}
	return (0);
}

void	draw_piece(t_win *win, t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < env->size_form_y)
	{
		x = 0;
		while (x < env->size_form_x)
		{
			SDL_SetRenderDrawColor(win->render, 100, 100, 100, 255);
			if (env->piece[y][x] == '.')
				draw_square(win->render, win->size_piece, win->size_piece,
									(win->size_plateau * env->size_map_x + 100) + (x * win->size_piece),
									(y * win->size_piece) + 100);
			else if (env->piece[y][x] == '*')
			{
				SDL_SetRenderDrawColor(win->render, 156, 100, 200, 255);
				draw_square(win->render, win->size_piece, win->size_piece,
									(win->size_plateau * env->size_map_x + 100) + (x * win->size_piece),
									(y * win->size_piece) + 100);
			}
			++x;
		}
		++y;
	}
}

void	draw(t_win *win, t_env *env)
{
	int	x;
	int	y;

	y = 0;
	sdl_clear(win);
	while (y < env->size_map_y)
	{
		x = 0;
		while (x < env->size_map_x)
		{
			SDL_SetRenderDrawColor(win->render, 100, 100, 100, 255);
			if (env->map[y][x] == '.')
				draw_square(win->render, win->size_plateau, win->size_plateau,
									 x * win->size_plateau, y * win->size_plateau);
			else if (env->map[y][x] == 'X' || env->map[y][x] == 'x')
			{
				SDL_SetRenderDrawColor(win->render, 255, 0, 0, 255);
				draw_square(win->render, win->size_plateau, win->size_plateau,
									 x * win->size_plateau, y * win->size_plateau);
			}
			else if (env->map[y][x] == 'O' || env->map[y][x] == 'o')
			{
				SDL_SetRenderDrawColor(win->render, 0, 255, 0, 255);
				draw_square(win->render, win->size_plateau, win->size_plateau,
									 x * win->size_plateau, y * win->size_plateau);
			}
			++x;
		}
		++y;
	}
	draw_piece(win, env);
	draw_grille(env, win, env->size_map_x * win->size_plateau, env->size_map_y * win->size_plateau);
	draw_grille(env, win, (env->size_map_x * win->size_plateau) *2,
						  (env->size_map_y * win->size_plateau));
	SDL_RenderPresent(win->render);
	if (env->size_form_x > env->size_map_x /2 || env->size_form_y > env->size_map_y /2)
	{
		ft_fprintf(2, "x = %d, y = %d\n", env->size_form_x, env->size_form_y);
	}
}

