#include "../include/filler.h"

static void	draw_square(SDL_Renderer *render, int width_x, int width_y, int pos_x, int pos_y)
{
	int	x;
	int	y;

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

static void	draw_grille(t_win *win, int	map_x, int map_y)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	SDL_SetRenderDrawColor(win->render, 0, 0, 0, 255);
	SDL_SetRenderDrawColor(win->render2, 0, 0, 0, 255);
	while (y < map_y)
	{
		SDL_RenderDrawLine(win->render, 0, y, map_x, y);
		SDL_RenderDrawLine(win->render2, 0, y, map_x, y);
		y += win->size_plateau;
	}
	while (x < map_x)
	{
		SDL_RenderDrawLine(win->render, x, 0, x, map_y);
		SDL_RenderDrawLine(win->render2, x, 0, x, map_y);
		x += win->size_plateau;
	}
}


static void	draw_piece(t_win *win, t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < env->size_form_y)
	{
		x = 0;
		while (x < env->size_form_x)
		{
			SDL_SetRenderDrawColor(win->render2, 100, 100, 100, 255);
			if (env->piece[y][x] == '.')
				draw_square(win->render2, win->size_piece, win->size_piece,
							(x * win->size_piece), (y * win->size_piece));
			else if (env->piece[y][x] == '*')
			{
				SDL_SetRenderDrawColor(win->render2, 0, 78, 255, 255);
				draw_square(win->render2, win->size_piece, win->size_piece,
							(x * win->size_piece), (y * win->size_piece));
			}
			++x;
		}
		++y;
	}
}

static void	draw_plateau(t_env *env, t_win *win, int x, int y)
{
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
}

void		draw(t_win *win, t_env *env)
{
	int	x;
	int	y;

	y = 0;
	sdl_clear(win);
	while (y < env->size_map_y)
	{
		x = 0;
		draw_plateau(env, win, x, y);
		++y;
	}
	draw_piece(win, env);
	draw_grille(win, env->size_map_x * win->size_plateau,
				env->size_map_y * win->size_plateau);
	draw_grille(win, (env->size_map_x * win->size_plateau) * 2,
				(env->size_map_y * win->size_plateau));
	SDL_RenderPresent(win->render);
	SDL_RenderPresent(win->render2);
}

