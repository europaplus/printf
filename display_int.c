/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 23:21:20 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/15 18:00:15 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_arg(t_print *print)
{
	int		num;
	int		minus;

	num = 0;
	minus = 0;
	num = va_arg(print->ap, int);
	print->num = num;
	if (num < 0)
	{
		minus = 1;
		num = num * -1;
	}
	if (num == 0 && print->precision == -1 && print->nocta != 1)
		print->len_arg = 1;
	while (num != 0)
	{
		print->len_arg++;
		num /= 10;
	}
	return (minus);
}

static void	hasnt_flag(t_print *print)
{
	int		i;
	int		minus;
	int		precision;

	precision = 0;
	minus = 0;
	i = 0;
	minus = len_arg(print);
	if (print->precision > print->len_arg)
		precision = print->precision - print->len_arg;
	if (print->width)
	{
		if (minus == 1)
			print->len_arg++;
		while (i++ < print->width - precision - print->len_arg)
			ft_putchar_len(' ', print);
		i = 0;
	}
	if (minus == 1)
		ft_putchar_len('-', print);
	while (i++ < precision)
		ft_putchar_len('0', print);
	if (print->len_arg > 0)
		ft_putnbr(print->num, print);
}

static void	treat_minus(t_print *print)
{
	int		i;
	int		minus;
	int		precision;

	precision = 0;
	minus = 0;
	i = 0;
	minus = len_arg(print);
	if (print->precision > print->len_arg)
		precision = print->precision - print->len_arg;
	if (minus == 1)
		ft_putchar_len('-', print);
	while (i++ < precision)
		ft_putchar_len('0', print);
	if (print->len_arg > 0)
		ft_putnbr(print->num, print);
	if (print->width)
	{
		i = 0;
		if (minus == 1)
			print->len_arg++;
		while (i++ < print->width - precision - print->len_arg)
			ft_putchar_len(' ', print);
	}
}

static void	treat_null(t_print *print)
{
	int		i;
	int		minus;
	int		precision;

	precision = 0;
	minus = 0;
	i = 0;
	minus = len_arg(print);
	if (print->width && print->precision != -1)
	{
		if (print->precision > print->len_arg)
			precision = print->precision - print->len_arg;
		(minus == 1) ? print->len_arg++ : print->len_arg;
		while (i++ < print->width - precision - print->len_arg)
			ft_putchar_len(' ', print);
		i = 0;
	}
	else
		precision = print->width - print->len_arg - minus;
	if (minus == 1)
		ft_putchar_len('-', print);
	while (i++ < precision)
		ft_putchar_len('0', print);
	if (print->len_arg > 0)
		ft_putnbr(print->num, print);
}

void		display_int(t_print *print)
{
	if (!print->flags[0] && !print->flags[1])
		hasnt_flag(print);
	else if (print->flags[0] && print->flags[1])
		treat_minus(print);
	else if (print->flags[0])
		treat_minus(print);
	else if (print->flags[1])
		treat_null(print);
}
