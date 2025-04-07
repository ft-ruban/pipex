/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:26:58 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/25 10:01:49 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		return_value;
	int		*ptr_return_value;

	if (str == NULL)
		return (-1);
	va_start(ptr, str);
	return_value = 0;
	ptr_return_value = &return_value;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			i += ft_printf_cases(ptr, i, str, ptr_return_value);
		else
		{
			write(1, &str[i++], 1);
			return_value += 1;
		}
	}
	va_end(ptr);
	return (return_value);
}
