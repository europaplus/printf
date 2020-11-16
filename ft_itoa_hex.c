/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:24:48 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/14 17:34:45 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	digit_count(long nb, int base)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_hex(unsigned int value, int base)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;

	if (value == 0)
		return ("0");
	tab_base = (char *)malloc(sizeof(char) * 17);
	tab_base = "0123456789abcdef";
	taille = digit_count(value, base);
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	i = 1;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
	return (ret);
}
