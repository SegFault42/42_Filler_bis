/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:39:37 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/22 03:19:24 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	get_piece(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	get_size_piece(env);
	env->piece = (char **)malloc(sizeof(char *) * env->size_piece_y);
	while (i < env->size_piece_y)
	{
		get_next_line(STDIN_FILENO, &line);
		env->piece[i] = ft_strdup(line);
		++i;
		free(line);
	}
}

void	get_size_piece(t_env *env)
{
	char	*line;
	char	*len;
	int		i;

	i = 0;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strstr(line, "Piece ") != NULL)
		{
			while (ft_isdigit(line[i]) != 1)
				++i;
			env->size_piece_y = ft_atoi(&line[i]);
			len = ft_itoa(env->size_piece_y);
			i += ft_strlen(len);
			free(len);
			env->size_piece_x = ft_atoi(&line[i]);
			free(line);
			return ;
		}
		free(line);
	}
}

void	get_map(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	get_size_map(env);
	env->map = (char **)malloc(sizeof(char *) * env->size_map_y);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strstr(line, "000 ") != NULL)
		{
			env->map[i] = ft_strdup(&line[4]);
			++i;
			free(line);
			break ;
		}
		free(line);
	}
	while (i < env->size_map_y)
	{
		get_next_line(STDIN_FILENO, &line);
		env->map[i] = ft_strdup(&line[4]);
		++i;
		free(line);
	}
	env->step = 1;
}

void	get_size_map(t_env *env)
{
	char	*line;
	int		i;
	char	*len;

	i = 0;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strstr(line, "Plateau ") != NULL)
		{
			while (ft_isdigit(line[i]) != 1)
				++i;
			env->size_map_y = ft_atoi(&line[i]);
			len = ft_itoa(env->size_map_y);
			i += ft_strlen(len);
			free(len);
			env->size_map_x = ft_atoi(&line[i]);
			free(line);
			return ;
		}
		free(line);
	}
}

void	get_info_header(t_env *env, char **argv)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p1") != NULL)
		{
			if (ft_strstr(line, argv[0]) != NULL)
			{
				env->rabougue = 1;
				env->ennemi = 2;
			}
			else
			{
				env->ennemi = 1;
				env->rabougue = 2;
			}
			free(line);
			return ;
		}
		free(line);
	}
}
