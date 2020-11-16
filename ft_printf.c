/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:56:57 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/16 11:36:04 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	t_print	*print;

	if (!(print = (t_print *)malloc(sizeof(t_print) + 1)))
		return (-1);
	print->format = format;
	ft_init(print);
	if (format)
	{
		va_start(print->ap, format);
		ft_parser(print);
		va_end(print->ap);
	}
	free(print);
	return (print->len);
}
