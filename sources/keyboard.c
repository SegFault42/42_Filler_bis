#include "../include/filler.h"

static void	key1(SDL_Event *event, t_env *env, t_win *win, char *argv)
{
	if (event->key.type == SDL_KEYDOWN && event->key.repeat == 0)
	{
		if (event->key.keysym.sym == SDLK_RETURN)
		{
			if (Mix_PausedMusic() == 1)
				Mix_ResumeMusic();
			else
				Mix_PauseMusic();
		}
		if (event->key.keysym.sym == SDLK_SPACE)
			SDL_Delay(2000);
		if (event->key.keysym.sym == SDLK_ESCAPE)
			quit_filler(env, win, argv);
	}
}

static void	screenshot(t_env *env, t_win *win)
{
	SDL_Surface	*p_screen;

	p_screen = SDL_CreateRGBSurface(0, WIN_WIDTH, WIN_HEIGHT,
									32, 0, 0, 0, 0);
	SDL_RenderReadPixels(win->render, NULL, SDL_PIXELFORMAT_ARGB8888
						, p_screen->pixels, p_screen->pitch);
	SDL_SaveBMP(p_screen, "Screenshot.bmp");
	SDL_FreeSurface(p_screen);
}

int			event(t_env *env, t_win *win, t_bonus *bonus, char *argv)
{
	SDL_Event	event;

	if (SDL_PollEvent(&event))
	{
		key1(&event, env, win, argv);
		if (event.key.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_MINUS)
				bonus->volume -= 10;
			if (event.key.keysym.sym == SDLK_EQUALS)
				bonus->volume += 10;
			if (event.key.keysym.sym == SDLK_p)
				screenshot(env, win);
		}
	}
	if (bonus->volume >= 128)
		bonus->volume = 128;
	else if (bonus->volume <= 12)
		bonus->volume = 12;
	Mix_VolumeMusic(bonus->volume);
	return (0);
}
