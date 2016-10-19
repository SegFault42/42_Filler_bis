#include "../include/filler.h"

static SDL_Texture	*surface_to_texture(SDL_Surface* surf, t_win *win)
{
	SDL_Texture	*text;
	text = SDL_CreateTextureFromSurface(win->render, surf);
	SDL_FreeSurface( surf );
	return text;
}

void				sdl_draw_text(t_win *win, t_env *env)
{
	SDL_Color	color = {255, 255, 255};

	win->text = TTF_RenderText_Solid(win->police, "Current piece", color);
	win->texture = surface_to_texture(win->text, win);
	SDL_QueryTexture(win->texture, NULL, NULL, &win->rect.w, &win->rect.h );
	win->rect.x = win->size_plateau * env->size_map_x + 10;
	win->rect.y = 0;
	SDL_RenderCopy(win->render, win->texture, NULL, &win->rect );
}
