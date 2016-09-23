/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 17:46:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/23 04:43:36 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

typedef struct	s_env
{
	char		**map;
	char		**piece;
	int			rabougue;
	int			ennemi;
	int			size_map_x;
	int			size_map_y;
	int			step;
	int			size_form_x;
	int			size_form_y;
	int			len_piece_x;
	int			len_piece_y;
}				t_env;
/*
** get_info.c
*/
void			get_info_header(t_env *env, char **argv);
void			get_size_map(t_env *env);
void			get_map(t_env *env);
void			get_piece(t_env *env);
void			get_size_piece(t_env *env);
/*
** tools.c
*/
void			init_struct(t_env *env);
void			tab_free(char **tab, int size);
void			alloc_map(t_env *env);
void			re_init(t_env *env);

#endif
