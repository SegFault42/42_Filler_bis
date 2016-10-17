#include "../include/filler.h"

void	count_empty_line_form_up(t_env *env)
{
	int	i = 0;

	while (ft_strstr(env->piece[i], "*") == NULL)
		i++;
	env->empty_line_form_up = i;
}

void	count_empty_line_form_down(t_env *env)
{
	int	i = env->size_form_y -1;
	int	j = 0;

	while (ft_strstr(env->piece[i], "*") == NULL)
	{
		i--;
		j++;
	}
	env->empty_line_form_down = j;
}

void	count_empty_point_form_left(t_env *env)
{
	int	x = 0;
	int	y = 0;
	int	point = 0;

	env->empty_point_form_left = env->size_form_x;
	while (y < env->size_form_y)
	{
		while (env->piece[y][x] == '.')
		{
			++point;
			++x;
		}
		if (point < env->empty_point_form_left)
			env->empty_point_form_left = point;
		point = 0;
		x = 0;
		++y;
	}
}
