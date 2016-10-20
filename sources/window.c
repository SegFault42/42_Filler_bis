/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:18:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/19 12:27:17 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		init_window(int width, int height, t_win *win)
{
	win->loop = 1;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		ft_putendl_fd("Failed to init SDL Video.", 2);
		return (EXIT_FAILURE);
	}
	win->win = SDL_CreateWindow("Filler by Rabougue (Plateau)", 100, 100,
				width, height, SDL_WINDOW_BORDERLESS);
	win->win2 = SDL_CreateWindow("Filler by Rabougue (Piece)", win->size_plateau
				+ width + 100, 100, width, height, SDL_WINDOW_BORDERLESS);
	if (win->win == NULL)
	{
		ft_putstr_fd("Could not create window : ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		exit(1);
	}
	win->render = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_SOFTWARE);
	win->render2 = SDL_CreateRenderer(win->win2, -1, SDL_RENDERER_SOFTWARE);
	return (0);
}

void	sdl_clear(t_win *win)
{
	SDL_SetRenderDrawColor(win->render2, 0, 0, 0, 0);
	SDL_RenderClear(win->render2);
}

void	close_window(t_win *win)
{
	SDL_DestroyRenderer(win->render);
	SDL_DestroyRenderer(win->render2);
	SDL_DestroyWindow(win->win);
	SDL_DestroyWindow(win->win2);
	SDL_Quit();
}
