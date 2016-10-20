#include "../include/filler.h"

static void	re_init_fful(t_env * env, t_fful *fful)
{
	fful->me = 0;
	fful->ennemi = 0;
	fful->piece_y = 0;
	fful->piece_x = 0;
	fful->map_x++;
	if (fful->map_x + env->size_form_x > env->size_map_x)
	{
		fful->map_x = 0;
		++fful->map_y;
	}
}

static void	init_fful(t_fful *fful)
{
	fful->piece_x = 0;
	fful->piece_y = 0;
	fful->me = 0;
	fful->ennemi = 0;
	fful->map_x = 0;
	fful->map_y = 0;
}

static int	fill_from_up_left_2(t_env *env, t_fful *fful)
{
	++fful->piece_y;
	if (fful->piece_y == env->size_form_y)
	{
		if (fful->me == 1 && fful->ennemi == 0)
		{
			if (fful->map_y + (env->size_piece_y) <= env->size_map_y &&
			fful->map_x + (env->size_piece_x) <= env->size_map_x)
			{
				print_coord(fful->map_y, fful->map_x);
				return (EXIT_SUCCESS);
			}
			else
			{
				print_coord(0, 0);
				return (EXIT_SUCCESS);
			}
		}
		else
			re_init_fful(env, fful);
	}
	return (EXIT_FAILURE);
}

void	fill_from_up_left(t_env *env)
{
	t_fful	fful;

	init_fful(&fful);
	while (fful.piece_y < env->size_form_y)
	{
		if (fful.map_y > env->size_map_y - env->size_form_y)
		{
			print_coord(0, 0);
			return ;
		}
		fful.piece_x = 0;
		while (fful.piece_x < env->size_form_x)
		{
			if ((env->map[ULPY + ULMY][ULPX + ULMX] == env->player_min[0] ||
				env->map[ULPY + ULMY][ULPX + ULMX] == env->player[0]) &&
				env->piece[ULPY][ULPX] == '*')
				fful.me++;
			else if (env->map[ULPY + ULMY][ULPX + ULMX] != '.' &&
			env->piece[ULPY][ULPX] == '*')
				fful.ennemi++;
			++fful.piece_x;
		}
		if (fill_from_up_left_2(env, &fful) == EXIT_SUCCESS)
			return ;
	}
}
