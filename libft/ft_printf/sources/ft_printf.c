/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/03 02:08:30 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	count_buff_size(t_printf *print, const char *format, va_list pa)
{
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			while (*format == ' ')
				++format;
			if (*format == 'c')
				percent_c(print, pa);
			else if (*format == 'd')
				percent_d(print, pa);
			else if (*format == 's')
				percent_s(print, pa);
			else
				++print->buff_size;
		}
		else
			++print->buff_size;
		++format;
	}
}

void	specifier(const char *format, va_list pa, t_printf *print)
{
	if (*format == 'c')
		percent_c(print, pa);
	else if (*format == 'd')
		percent_d(print, pa);
	else if (*format == 's')
		percent_s(print, pa);
}

void	write_string(t_printf *print, const char *format, va_list pa)
{
	print->buff = (char *)malloc(sizeof(char) * print->buff_size + 1);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			while (*format == ' ')
				++format;
			if (*format == '%')
			{
				strcat(print->buff, "%");
				print->i++;
			}
			specifier(format, pa, print);
		}
		else
		{
			print->buff[print->i] = *format;
			++print->i;
		}
		++format;
	}
	print->buff[print->i] = '\0';
	ft_putstr(print->buff);
	free(print->buff);
}

int		ft_printf(const char *format, ...)
{
	t_printf	print;
	va_list		pa;

	va_start(pa, format);
	init_struct(&print);
	if (*format == '%' && ft_strlen(format) == 1)
		return (0);
	count_buff_size(&print, format, pa);
	va_end(pa);
	print.is_percent_s = 1;
	print.is_percent_d = 1;
	print.is_percent_c = 1;
	va_start(pa, format);
	write_string(&print, format, pa);
	va_end(pa);
	return (ft_strlen(print.buff));
}
