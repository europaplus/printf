/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:28:11 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/15 14:36:13 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_print *print)
{
	print->i = 0;
	print->flags[0] = '\0';
	print->flags[1] = '\0';
	print->width = 0;
	print->precision = -1;
	print->len_arg = 0;
	print->num = 0;
	print->str = "\0";
	print->len = 0;
	print->nocta = 0;
	print->nump = 0;
}
