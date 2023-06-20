/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:16:21 by brunrodr          #+#    #+#             */
/*   Updated: 2023/06/20 13:41:27 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *arg)
{
	int	length;

	length = 0;
	if (!arg)
		arg = "(null)";
	while (*arg)
	{
		length += write(1, arg, 1);
		arg++;
	}
	return (length);
}
