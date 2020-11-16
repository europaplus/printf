/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:34:47 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/13 20:48:55 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(char ch)
{
	if (ch - 48 >= 0 && ch - 48 <= 9)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}
