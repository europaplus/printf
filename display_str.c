/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:46:04 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/15 19:53:54 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	output_str(t_print *print)
{
	int		i;

	i = 0;
	while (i < print->len_arg)
	{
		ft_putchar_len(print->str[i], print);
		i++;
	}
}

static void	hasnt_flag(t_print *print)
{
	int		i;
	int		precision;

	precision = 0;
	i = 0;
	print->len_arg = ft_strlen(print->str);
	if (print->precision != -1 && print->precision <= print->len_arg)
		print->len_arg = print->precision;
	if (print->precision == -1 && print->nocta == 1)
		print->len_arg = 0;
	if (print->precision < 0 && print->nocta == 2)
		print->len_arg = ft_strlen(print->str);
	if (print->width)
	{
		while (i++ < print->width - print->len_arg)
			ft_putchar_len(' ', print);
	}
	output_str(print);
}

static void	treat_minus(t_print *print)
{
	int		i;
	int		precision;

	precision = 0;
	i = 0;
	print->len_arg = ft_strlen(print->str);
	if (print->precision != -1 && print->precision <= print->len_arg)
		print->len_arg = print->precision;
	if (print->precision == -1 && print->nocta == 1)
		print->len_arg = 0;
	if (print->precision < 0 && print->nocta == 2)
		print->len_arg = ft_strlen(print->str);
	output_str(print);
	if (print->width)
	{
		while (i++ < print->width - print->len_arg)
			ft_putchar_len(' ', print);
	}
}

void		display_str(t_print *print)
{
	int		i;
	int		precision;

	precision = 0;
	i = 0;
	print->str = va_arg(print->ap, char *);
	if (print->str == 0 || (print->precision < 0 && print->nocta == 2\
	&& print->str == 0))
		print->str = "(null)";
	if (!print->flags[0] && !print->flags[1])
		hasnt_flag(print);
	else if (print->flags[0] && print->flags[1])
		treat_minus(print);
	else if (print->flags[0])
		treat_minus(print);
	else if (print->flags[1])
		hasnt_flag(print);
}
