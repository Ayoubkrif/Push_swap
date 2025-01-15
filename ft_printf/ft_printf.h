/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:49:18 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 08:42:54 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_conversion{
	CHARACTER,
	INTEGER,
	HEXA_LOW,
	HEXA_UP,
	POINTER_ADDR,
	UNSIGNED_INTEGER,
	STRING,
	PERCENT,
	NONE,
}t_conversion;

int				ft_printf(const char *format, ...);
t_conversion	ft_is(const char c);
void			ft_printf_c(char arg, int *count);
void			ft_printf_s(char *arg, int *count);
void			ft_printf_p(void *arg, int *count);
void			ft_printf_xup(unsigned int arg, int *count);
void			ft_printf_x(unsigned int arg, int *count);
void			ft_printf_i(int arg, int *count);
void			ft_printf_u(unsigned int arg, int *count);
void			ft_printf_per(int *count);
void			ft_putchar_count(char c, int *count);
void			ft_printer(char format, va_list args, int *count);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);

#endif
