/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:39:37 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/23 04:44:22 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	print_coord(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	RC;
}

void	get_piece(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	get_size_piece(env);
	while (i < env->size_form_y)
	{
		get_next_line(STDIN_FILENO, &line);
		ft_memmove(env->piece[i], line, env->size_form_x);
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
	line = NULL;
	len = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strstr(line, "Piece ") != NULL)
		{
			while (ft_isdigit(line[i]) != 1)
				++i;
			env->size_form_y = ft_atoi(&line[i]);
			len = ft_itoa(env->size_form_y);
			i += ft_strlen(len);
			free(len);
			env->size_form_x = ft_atoi(&line[i]);
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
	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_isdigit(line[0]) != 0)
		{
			ft_memmove(env->map[i], &line[4], env->size_map_x);
			++i;
		}
		if (i == env->size_map_y)
		{
			free(line);
			break ;
		}
		free(line);
	}
}

void	get_size_map(t_env *env)
{
	char	*line;
	int		i;
	char	*len;

	i = 0;
	line = NULL;
	len = NULL;
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
