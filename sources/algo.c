#include "../include/filler.h"

/*=============================================================================
** Check who is higher and who is first player. See filler.h for more info.
*/
static int	check_who_is_higher_2(t_env *env, int i)
{
	if (ft_strstr(env->map[i], "X") != NULL)
	{
		if (env->player[0] == 'O')
		{
			env->rabougue = 4;
			env->ennemi = 5;
		}
		else if (env->player[0] == 'X')
		{
			env->rabougue = 5;
			env->ennemi = 4;
		}
		return (1);
	}
	return (0);
}

int			check_who_is_higher(t_env *env)
{
	int	i;

	i = 0;
	while (i++ < env->size_map_y)
	{
		if (ft_strstr(env->map[i], env->player) != NULL ||
			ft_strstr(env->map[i], env->player_min) != NULL)
		{
			if (env->player[0] == 'O')
			{
				env->rabougue = 3;
				env->ennemi = 6;
			}
			else if (env->player[0] == 'X')
			{
				env->rabougue = 6;
				env->ennemi = 3;
			}
			return (1);
		}
		else
			if (check_who_is_higher_2(env, i) == 1)
				return (1);
	}
	return (-1);
}

void		where_is_the_lower(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < env->size_map_y)
	{
		if (ft_strstr(env->map[y], env->player) != NULL ||
			ft_strstr(env->map[y], env->player_min) != NULL)
			env->last_y = y;
		++y;
	}
	while (x < env->size_map_x)
	{
		if (env->map[env->last_y][x] == ft_tolower(env->player[0]) ||
			env->map[env->last_y][x] == env->player[0])
			env->last_x = x;
		++x;
	}
}

int			check_if_ennemi(t_env *env)
{
	int	x = 0;
	int	y = 0;

	if (env->last_y + env->size_form_y > env->size_map_y)
		return (EXIT_FAILURE);
	while (y < env->size_form_y)
	{
		x = 0;
		while (x < env->size_form_x)
		{
			if (env->map[env->last_y + y][env->last_x + x] != '.')
				return (EXIT_FAILURE);
			++x;
		}
		++y;
	}
	return (EXIT_SUCCESS);
}

void		split_map(t_env *env)
{
	where_is_the_lower(env);
	if (env->rabougue == 3)
		place_piece(env);
	else if (env->rabougue == 4 &&
	ft_strstr(env->map[env->size_map_y - 1], env->player) != NULL &&
			ft_strstr(env->map[0], env->player) != NULL)
	{
		count_empty_line_form_up(env);
		count_empty_line_form_down(env);
		env->size_form_y -= env->empty_line_form_down;
		fill_from_up_left(env);
	}
	else
		place_piece(env);
}
