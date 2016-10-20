#include "../include/filler.h"

void	init_bonus_struct(t_bonus *bonus)
{
	bonus->x = -1;
	bonus->y = -1;
	bonus->nb_o = 0;
	bonus->nb_x = 0;
	bonus->nb_point = 0;
	bonus->volume = 128;
}

void	sdl_init(t_win *win, t_env *env, char *argv)
{
	win->loop = 1;
	if (env->size_map_x < 25 )
		win->size_plateau = 30;
	else if (env->size_map_x >= 25 && env->size_map_x < 70)
		win->size_plateau = 20;
	else
		win->size_plateau = 8;
	win->size_piece = win->size_plateau;
	init_window(WIN_WIDTH, WIN_HEIGHT, win);
	if (env->b_sound == 1)
	{
		SDL_Init(SDL_INIT_AUDIO);
		Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
		win->music = Mix_LoadMUS("./media/sound/Music2.mp3");
		Mix_PlayMusic(win->music, -1);
	}
}

void	init_bonus_arg(t_env *env, char **argv)
{
	if (argv[1] != NULL && ft_strstr(argv[1], "graphic") != NULL)
		env->b_graphic = 1;
	if (argv[1] != NULL && ft_strstr(argv[1], "s") != NULL)
		env->b_sound = 1;
}
