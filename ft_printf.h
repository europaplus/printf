/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:34:37 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/16 11:30:27 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_print
{
	char			*format;
	char			flags[2];
	int				width;
	int				precision;
	int				nocta;
	int				len_arg;
	int				num;
	unsigned long	nump;
	char			*str;
	va_list			ap;
	int				i;
	int				len;
}				t_print;

int				ft_printf(char *format, ...);

void			ft_putchar_len(char c, t_print *print);
int				ft_isdigit(char ch);
size_t			ft_strlen(const char *str);
void			ft_putnbru(unsigned int nb, t_print *print);
void			ft_putnbr(int nb, t_print *print);
char			*ft_itoa_hex(unsigned int value, int base);
char			*ft_itoa_hexu(unsigned long value, int base);

void			ft_init(t_print *print);
void			ft_reinit(t_print *print);

void			display_str(t_print *print);
void			display_char(t_print *print);
void			display_int(t_print *print);
void			display_uint(t_print *print);
void			display_proc(t_print *print);
void			display_x(t_print *print);
void			display_xx(t_print *print);
void			display_p(t_print *print);
void			ft_parser(t_print *print);

#endif
