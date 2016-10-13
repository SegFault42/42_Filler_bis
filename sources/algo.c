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
	fful->map_x = 0;
	fful->map_y = 0;
	fful->me = 0;
	fful->ennemi = 0;
}

void	fill_from_up_left(t_env *env)
{
	t_fful	fful;

	init_fful(&fful);
	while (fful.piece_y < env->size_form_y)
	{
		if (fful.map_y > env->size_map_y - env->size_form_y)
		{
			ft_fprintf(1, "0 0\n");
			return ;
		}
		fful.piece_x = 0;
		while (fful.piece_x < env->size_form_x)
		{
			if ((env->map[fful.piece_y + fful.map_y][fful.piece_x + fful.map_x] == 'o' ||
				env->map[fful.piece_y + fful.map_y][fful.piece_x + fful.map_x] == 'O') &&
				env->piece[fful.piece_y][fful.piece_x] == '*')
				fful.me++;
			else if (env->map[fful.piece_y + fful.map_y][fful.piece_x + fful.map_x] == 'X' && env->piece[fful.piece_y][fful.piece_x] == '*')
				fful.ennemi++;
			/*ft_putchar(env->map[fful.piece_y + fful.map_y][fful.piece_x + fful.map_x]);*/
			++fful.piece_x;
		}
		/*RC;*/
		++fful.piece_y;
		if (fful.piece_y == env->size_form_y)
		{
			if (fful.me == 1 && fful.ennemi == 0)
			{
				/*ft_fprintf(2, RED"!");*/
				/*if (fful.map_y + (env->size_form_y - env->empty_line_form_up) > env->size_map_y ||*/
					/*fful.map_x + (env->size_form_x - env->empty_point_form_left) > env->size_map_x)*/
				/*{*/
					/*ft_fprintf(2, YELLOW"!");*/
					/*[>exit (1);<]*/
					/*ft_fprintf(1, "0 0\n");*/
					/*return ;*/
				/*}*/
				/*else*/
				/*{*/
					/*ft_fprintf(2, PURPLE"%d, %d\n", fful.map_y, env->size_map_y - env->size_form_y);*/
					if (fful.map_y + (env->size_form_y - env->empty_line_form_up) <= env->size_map_y &&
					fful.map_x + (env->size_form_x - env->empty_point_form_left) <= env->size_map_x)
					{
						ft_fprintf(1, "%d %d\n", fful.map_y, fful.map_x);
						return ;
					}
					else
					{
						ft_fprintf(1, "0 0\n");
						return ;
					}
				/*}*/
			}
			else
			{
				/*RC;*/
				re_init_fful(env, &fful);
			}
		}
	}
	/*sleep (10);*/
}

static int	calc_dist_left_and_last_o(t_env *env, t_ffdr *ffdr)
{
	/*int x = env->size_map_x - env->size_form_x;*/
	/*int y = env->size_map_y - env->size_form_y;*/
	int	x = ffdr->map_x;
	int	y = ffdr->map_y;

	while (env->map[y][x] != 'O')
		--x;
	return (x);
}

static void	init_ffdr(t_ffdr *ffdr, t_env *env)
{
	ffdr->piece_x = 0;
	ffdr->piece_y = 0;
	ffdr->map_x = env->size_map_x - env->size_form_x;
	ffdr->map_y = env->size_map_y - env->size_form_y;
	ffdr->me = 0;
	ffdr->ennemi = 0;
	ffdr->dist_left_and_last_o = calc_dist_left_and_last_o(env, ffdr);
}

static void	re_init_ffdr(t_env *env, t_ffdr *ffdr)
{
	ffdr->me = 0;
	ffdr->ennemi = 0;
	ffdr->piece_y = 0;
	ffdr->piece_x = 0;
	ffdr->map_x--;
	if (ft_strstr(env->map[env->size_map_y - 1], "O") != NULL && ft_strstr(env->map[0], "O") != NULL)
	{
		if (ffdr->map_x + env->size_form_x < ffdr->dist_left_and_last_o)
		{
			ffdr->map_x = env->size_map_x - env->size_form_x;
			--ffdr->map_y;
			ffdr->dist_left_and_last_o = calc_dist_left_and_last_o(env, ffdr);
		}
		else
		{
			--ffdr->map_x;
		}
	}
	if (ffdr->map_x == -1)
	{
		ffdr->map_x = env->size_map_x - env->size_form_x;
		--ffdr->map_y;
	}
}

void	fill_from_down_right(t_env *env)
{
	t_ffdr	ffdr;

	init_ffdr(&ffdr, env);
	while (ffdr.piece_y < env->size_form_y)
	{
		if (ffdr.map_y == 0)
		/*if (ffdr.map_y > env->size_map_y - env->size_form_y)*/
		{
			fill_from_up_left(env);
			/*ft_fprintf(1, "0 0\n");*/
			return ;
		}
		ffdr.piece_x = 0;
		while (ffdr.piece_x < env->size_form_x)
		{
			if ((env->map[ffdr.piece_y + ffdr.map_y][ffdr.piece_x + ffdr.map_x] == 'o' || env->map[ffdr.piece_y + ffdr.map_y][ffdr.piece_x + ffdr.map_x] == 'O') &&
				env->piece[ffdr.piece_y][ffdr.piece_x] == '*')
				ffdr.me++;
			else if (env->map[ffdr.piece_y + ffdr.map_y][ffdr.piece_x + ffdr.map_x] == 'X' && env->piece[ffdr.piece_y][ffdr.piece_x] == '*')
				ffdr.ennemi++;
			/*ft_putchar(env->map[ffdr.piece_y + ffdr.map_y][ffdr.piece_x + ffdr.map_x]);*/
			++ffdr.piece_x;
		}
		/*RC;*/
		++ffdr.piece_y;
		if (ffdr.piece_y == env->size_form_y)
		{
		/*printf("me = %d, ennemi = %d\n", ffdr.me, ffdr.ennemi);*/
		/*sleep(1);*/
			if (ffdr.me == 1 && ffdr.ennemi == 0)
			{
				if (ffdr.map_y + (env->size_form_y - env->empty_line_form_up) <= env->size_map_y && ffdr.map_x + (env->size_form_x - env->empty_point_form_left) <= env->size_map_x)
				{
					if (ffdr.map_x < 0)
						fill_from_up_left(env);
					else
					{
						/*ft_fprintf(1, "%d %d\n", ffdr.map_y, ffdr.map_x);*/
						ft_putnbr(ffdr.map_y);
						ft_putchar(' ');
						ft_putnbr(ffdr.map_x);
						RC;
					}
					return ;
				}
				else
				{
					ft_fprintf(1, "0 0\n");
					return ;
				}
			}
			else
			{
				/*RC;*/
				re_init_ffdr(env, &ffdr);
			}
		}
	}
	/*sleep (10);*/
}
