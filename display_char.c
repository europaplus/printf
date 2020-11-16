/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:48:01 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/15 19:53:10 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hasnt_flag(t_print *print)
{
	int		i;
	char	ch;

	ch = (char)va_arg(print->ap, int);
	i = 0;
	if (print->width)
	{
		while (i++ < print->width - 1)
			ft_putchar_len(' ', print);
	}
	ft_putchar_len(ch, print);
}

static void	treat_null(t_print *print)
{
	int		i;
	char	ch;

	ch = (char)va_arg(print->ap, int);
	i = 0;
	if (print->width)
	{
		while (i++ < print->width - 1)
			ft_putchar_len('0', print);
	}
	ft_putchar_len(ch, print);
}

static void	treat_minus(t_print *print)
{
	int		i;
	char	ch;

	ch = (char)va_arg(print->ap, int);
	i = 0;
	ft_putchar_len(ch, print);
	if (print->width)
	{
		while (i++ < print->width - 1)
			ft_putchar_len(' ', print);
	}
}

void		display_char(t_print *print)
{
	if (!print->flags[0] && !print->flags[1])
	{
		hasnt_flag(print);
	}
	else if (print->flags[0] && print->flags[1])
	{
		treat_minus(print);
	}
	else if (print->flags[0])
	{
		treat_minus(print);
	}
	else if (print->flags[1])
	{
		treat_null(print);
	}
}
