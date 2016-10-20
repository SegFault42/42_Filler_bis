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

int			event(t_env *env, t_win *win, char *argv)
{
	SDL_Event				event;
	static unsigned char	volume = 128;

	if (SDL_PollEvent(&event))
	{
		key1(&event, env, win, argv);
		if (event.key.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_MINUS)
				volume -=10;
			if (event.key.keysym.sym == SDLK_EQUALS)
				volume +=10;
		}
	}
	if (volume >= 128)
		volume = 128;
	else if (volume <= 12)
		volume = 12;
	Mix_VolumeMusic(volume);
	return (0);
}
