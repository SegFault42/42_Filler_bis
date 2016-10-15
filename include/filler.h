/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 17:46:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/23 21:53:38 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
#include <stdio.h>

/*=============================================================================
** if a player == 1, the player is player one.
** if a player == 2, the player is player two.
** if a player == 3, the player is player one and he is higher in the map.
** if a player == 4, the player is player one and he is lower in the map.
** if a player == 5, the player is player two and he is higher in the map.
** if a player == 6, the player is player two and he is lower in the map.
*==============================================================================
*/
/*=============================================================================
** form = carre entier (donner par la vm)
** piece = uniquement la piece dessiner par les etoiles
*==============================================================================
*/
typedef struct	s_env
{
	char		**map;
	char		**piece;
//=============================================================================
	int			rabougue;
	int			ennemi;
//=============================================================================
	int			size_map_x;
	int			size_map_y;
//=============================================================================
	int			step;
//=============================================================================
	int			size_form_x;
	int			size_form_y;
//=============================================================================
	int			size_piece_x;
	int			size_piece_y;
//=============================================================================
	int			start;
//=============================================================================
	int			last_x;
	int			last_y;
//=============================================================================
	int			empty_line_form_up;
	int			empty_point_form_left;
//=============================================================================
	char		player;
}				t_env;

typedef struct	s_fful
{
	int			piece_x;
	int			piece_y;
	int			map_x;
	int			map_y;
	int			me;
	int			ennemi;
	int			dist_right_and_first_o;
}				t_fful;

typedef struct	s_ffdr
{
	int			piece_x;
	int			piece_y;
	int			map_x;
	int			map_y;
	int			me;
	int			ennemi;
	int			dist_left_and_last_o;
}				t_ffdr;

typedef struct	s_bonus
{
	int			x;
	int			y;
	int			nb_o;
	int			nb_x;
	int			nb_point;
}				t_bonus;
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
void			init_filler_struct(t_env *env);
void			tab_free(char **tab, int size);
void			alloc_map(t_env *env);
void			re_init(t_env *env);
void			who_is_x_or_o(t_env *env);
/*
** bonus.c
*/
void			init_bonus_struct(t_bonus *bonus);
void			aff_percent_map(t_bonus *bonus, t_env *env);
void			aff_map(t_env *env, t_bonus *bonus);

void			fill_from_up_left(t_env *env);
void			fill_from_down_right(t_env *env);
void			count_empty_line_form_up(t_env *env);
void			count_empty_point_form_left(t_env *env);

#endif
