/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 04:01:38 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/15 16:21:10 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, t_print *print)
{
	long i;
	char num;

	num = 0;
	i = nb;
	if (i < 0)
	{
		i = i * (-1);
	}
	if (i > 9)
	{
		ft_putnbr(i / 10, print);
		ft_putnbr(i % 10, print);
	}
	else
	{
		num = i + '0';
		print->len++;
		write(1, &num, 1);
	}
}
