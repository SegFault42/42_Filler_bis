#include "../include/filler.h"

static void	parse_p1(char *line, char **argv, t_env *env)
{
	if (ft_strstr(line, &argv[0][2]) != NULL)
	{
		env->rabougue = 0;
		env->player = ft_strdup("O");
		env->other = ft_strdup("X");
		env->player_min = ft_strdup("o");
		env->other_min = ft_strdup("x");
	}
	else
	{
		env->rabougue = 1;
		env->player = ft_strdup("X");
		env->other = ft_strdup("O");
		env->player_min = ft_strdup("x");
		env->other_min = ft_strdup("o");
	}
}

static void	parse_p2(char *line, char **argv, t_env *env)
{
	if (ft_strstr(line, &argv[0][2]) != NULL)
	{
		env->rabougue = 1;
		env->player = ft_strdup("X");
		env->other = ft_strdup("O");
		env->player_min = ft_strdup("x");
		env->other_min = ft_strdup("o");
	}
	else
	{
		env->rabougue = 0;
		env->player = ft_strdup("O");
		env->other = ft_strdup("X");
		env->player_min = ft_strdup("o");
		env->other_min = ft_strdup("x");
	}
}

void		get_info_header(t_env *env, char **argv)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p1") != NULL)
		{
			parse_p1(line, argv, env);
			free(line);
			return ;
		}
		else if (ft_strstr(line, "$$$ exec p2") != NULL)
		{
			parse_p2(line, argv, env);
			free(line);
			return ;
		}
		free(line);
	}
}
