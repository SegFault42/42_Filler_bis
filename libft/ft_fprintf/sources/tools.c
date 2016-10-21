/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: rabougue <rabougue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2015/11/24 18:34:24 by rabougue          #+#    #+#             */
/*   updated: 2016/09/15 17:17:48 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fprintf.h"

void	init_struct(t_printf *print)
{
	print->buff = NULL;
	print->buff_size = 0;
	print->ret = 0;
	print->is_percent_c = 0;
	print->is_percent_s = 0;
	print->is_percent_d = 0;
	print->i = 0;
}

void	print_buff(t_printf *print, int *fd)
{
	print->buff[print->i] = '\0';
	ft_putstr_fd(print->buff, *fd);
	free(print->buff);
}
