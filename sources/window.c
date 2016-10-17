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

int		init_window(char *win_name, int width, int height, t_win *win)
{
	win->loop = 1;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		ft_putendl_fd("Failed to init SDL Video.", 2);
		return (EXIT_FAILURE);
	}
	win->win = SDL_CreateWindow(win_name, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (win->win == NULL)
	{
		ft_putstr_fd("Could not create window : ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		exit(1);
	}
	win->render = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_SOFTWARE);
	return (0);
}

void	sdl_clear(t_win *win)
{
	SDL_SetRenderDrawColor(win->render, 0, 0, 0, 0);
	SDL_RenderClear(win->render);
	/*SDL_RenderPresent(win->render);*/
}

void	close_window(t_win *win)
{
	SDL_DestroyRenderer(win->render);
	SDL_DestroyWindow(win->win);
	SDL_Quit();
}
