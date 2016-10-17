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

static void	init_fful(t_fful *fful, t_env *env)
{
	fful->piece_x = 0;
	fful->piece_y = 0;
	fful->me = 0;
	fful->ennemi = 0;
	fful->map_x = 0;
	fful->map_y = 0;
	/*fful->dist_right_and_first_o = calc_dist_right_and_first_o(env, fful);*/
	(void)env;
}

static int	fill_from_up_left_2(t_env *env, t_fful *fful)
{
	++fful->piece_y;
	if (fful->piece_y == env->size_form_y)
	{
		if (fful->me == 1 && fful->ennemi == 0)
		{
			/*if (fful.map_y + ((env->size_form_y - env->empty_line_form_up)) <= env->size_map_y &&*/
				/*fful.map_x + (env->size_form_x - env->empty_point_form_left) <= env->size_map_x)*/
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

	init_fful(&fful, env);
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
			if ((env->map[fful.piece_y + fful.map_y][fful.piece_x + fful.map_x] == env->player_min[0] ||
				env->map[fful.piece_y + fful.map_y][fful.piece_x + fful.map_x] == env->player[0]) &&
				env->piece[fful.piece_y][fful.piece_x] == '*')
				fful.me++;
			else if (env->map[fful.piece_y + fful.map_y][fful.piece_x + fful.map_x] == env->other[0] &&
			env->piece[fful.piece_y][fful.piece_x] == '*')
				fful.ennemi++;
			/*ft_putchar_fd(env->map[fful.piece_y + fful.map_y][fful.piece_x + fful.map_x], 2);*/
			++fful.piece_x;
		}
		/*ft_putchar_fd('\n', 2);*/
		if (fill_from_up_left_2(env, &fful) == EXIT_SUCCESS)
			return ;
	}
}
