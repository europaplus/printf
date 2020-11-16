/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:01:18 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/15 20:22:56 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	output_int(t_print *print)
{
	int i;

	i = 0;
	if (print->num == 0 && print->len_arg > 0)
		ft_putnbr(0, print);
	else if (print->precision != 0)
		while (i < print->len_arg)
		{
			if (print->str[i] >= 'a' && print->str[i] <= 'z')
				print->str[i] = print->str[i] - 32;
			write(1, &print->str[i], 1);
			print->len++;
			i++;
		}
}

static void	hasnt_flag(t_print *print)
{
	int		i;
	int		precision;

	precision = 0;
	i = 0;
	if (print->precision > print->len_arg)
		precision = print->precision - print->len_arg;
	if (print->width)
	{
		while (i++ < print->width - precision - print->len_arg)
			ft_putchar_len(' ', print);
		i = 0;
	}
	while (i++ < precision)
		ft_putchar_len('0', print);
	output_int(print);
}

static void	treat_minus(t_print *print)
{
	int		i;
	int		precision;

	precision = 0;
	i = 0;
	if (print->precision > print->len_arg)
		precision = print->precision - print->len_arg;
	while (i++ < precision)
		ft_putchar_len('0', print);
	output_int(print);
	if (print->width)
	{
		i = 0;
		while (i++ < print->width - precision - print->len_arg)
			ft_putchar_len(' ', print);
	}
}

static void	treat_null(t_print *print)
{
	int		i;
	int		precision;

	precision = 0;
	i = 0;
	if (print->precision != -1)
	{
		if (print->precision > print->len_arg)
			precision = print->precision - print->len_arg;
		if (print->width)
		{
			while (i++ < print->width - precision - print->len_arg)
				ft_putchar_len(' ', print);
			i = 0;
		}
	}
	else
		precision = print->width - print->len_arg;
	while (i++ < precision)
		ft_putchar_len('0', print);
	output_int(print);
}

void		display_xx(t_print *print)
{
	print->num = va_arg(print->ap, unsigned int);
	if (print->nocta == 1 && (print->precision < 0 || print->precision == 0))
	{
		print->str = ft_itoa_hex(print->num, 16);
		print->len_arg = 0;
	}
	else
	{
		print->str = ft_itoa_hex(print->num, 16);
		print->len_arg = ft_strlen(print->str);
	}
	if (print->precision == 0)
		print->len_arg = 0;
	if (print->nocta == 2 && print->precision < 0)
	{
		print->str = ft_itoa_hex(print->num, 16);
		print->len_arg = ft_strlen(print->str);
	}
	if (!print->flags[0] && !print->flags[1])
		hasnt_flag(print);
	else if ((print->flags[0] && print->flags[1]) || print->flags[0])
		treat_minus(print);
	else if (print->flags[1])
		treat_null(print);
}
