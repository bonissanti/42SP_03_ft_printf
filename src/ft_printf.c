/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:30:09 by brunrodr          #+#    #+#             */
/*   Updated: 2023/06/15 19:09:20 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	check_uppercase(char format)
{
	if (format == 'X')
	{
		return (1);
	}
	return (0);
}

void	active_flags(char format, t_flags *flags)
{
	if (format == '#')
		flags->hashtag = 1;
}

int	convert_specifiers(const char *format, va_list args)
{
	int		index;
	int		uppercase;
	t_flags	flags = {0};

	index = 0;
	if (*format == '%')
	{
		format++;
		while (*format == '#' || *format == '0' || *format == '-'
			|| *format == '+' || *format == ' ')
		{
			active_flags(*format, &flags);
			format++;
		}
		uppercase = check_uppercase(*format);
		if (*format == 'c')
			index += print_char(va_arg(args, int));
		else if (*format == 's')
			index += print_string(va_arg(args, char *));
		else if (*format == 'p')
			index += print_pointer(va_arg(args, void *), 16);
		else if (*format == 'u')
			index += print_unsign_int(va_arg(args, unsigned int));
		else if (*format == 'd' || *format == 'i')
			index += print_int(va_arg(args, int));
		else if (*format == 'x' || *format == 'X')
			index += print_hex_d(va_arg(args, unsigned int), uppercase, flags);
		else if (*format == '%')
			index += print_percent();
	}
	return (index);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;

	index = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			index += convert_specifiers(str, args);
			str++;
		}
		else
			index += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (index);
}

int	main(void)
{
	ft_printf("%#x\n", 255);
	// ft_printf("%x\n", 255);
	// printf("%#d\n", 255);
	return (0);
}