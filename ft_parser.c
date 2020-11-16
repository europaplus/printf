/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:15:29 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/16 11:32:36 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags(t_print *print)
{
	while (print->format[print->i] == '-' || print->format[print->i] == '0')
	{
		if (print->format[print->i] == '-')
			print->flags[0] = '-';
		if (print->format[print->i] == '0')
			print->flags[1] = '0';
		print->i++;
	}
	return ;
}

static void	ft_width(t_print *print)
{
	if (print->format[print->i] == '*')
	{
		print->width = va_arg(print->ap, int);
		if (print->width < 0)
		{
			print->width = print->width * -1;
			print->flags[0] = '-';
		}
		print->i++;
	}
	else if ((print->format[print->i + 1]))
	{
		while (print->format[print->i] && ft_isdigit(print->format[print->i]))
		{
			print->width *= 10;
			print->width += print->format[print->i] - '0';
			print->i++;
		}
	}
	return ;
}

static void	ft_precision(t_print *print)
{
	if (!(print->format[print->i + 1]))
		return ;
	if (print->format[print->i] == '.')
	{
		print->i++;
		print->nocta = 1;
	}
	if (print->format[print->i] == '*')
	{
		print->precision = va_arg(print->ap, int);
		print->nocta = 2;
		print->i++;
	}
	else if (print->format[print->i] >= '0' && print->format[print->i] <= '9')
	{
		print->precision = 0;
		while (print->format[print->i]\
		&& ft_isdigit(print->format[print->i]))
		{
			print->precision *= 10;
			print->precision += print->format[print->i] - '0';
			print->i++;
		}
	}
}

static void	ft_modifier(t_print *print)
{
	if (print->format[print->i] == 'd' || print->format[print->i] == 'i')
		display_int(print);
	else if (print->format[print->i] == 'c')
		display_char(print);
	else if (print->format[print->i] == 's')
		display_str(print);
	else if (print->format[print->i] == 'p')
		display_p(print);
	else if (print->format[print->i] == 'u')
		display_uint(print);
	else if (print->format[print->i] == 'x')
		display_x(print);
	else if (print->format[print->i] == 'X')
		display_xx(print);
	else if (print->format[print->i] == '%')
		display_proc(print);
	else
	{
		print->i++;
		return ;
	}
}

void		ft_parser(t_print *print)
{
	while (print->format[print->i])
	{
		if (print->format[print->i] == '%')
		{
			print->i++;
			ft_reinit(print);
			ft_flags(print);
			ft_width(print);
			ft_precision(print);
			ft_modifier(print);
		}
		else
		{
			ft_putchar_len(print->format[print->i], print);
		}
		if (print->format[print->i])
			print->i++;
	}
	return ;
}
