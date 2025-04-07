/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:49:41 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/24 06:55:56 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert(long n, char *result, int length)
{
	result[length] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n > 0)
	{
		result[--length] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}

static char	*count_for_malloc(long integer, int is_negative, int *length)
{
	char	*result;

	if (is_negative || integer == 0)
		(*length)++;
	while (integer > 0)
	{
		integer /= 10;
		(*length)++;
	}
	result = malloc((*length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (is_negative)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		is_negative;
	long	ln;
	int		length;

	is_negative = 0;
	length = 0;
	result = NULL;
	ln = n;
	if (ln < 0)
	{
		is_negative = 1;
		ln *= -1;
	}
	result = count_for_malloc(ln, is_negative, &length);
	if (!result)
		return (NULL);
	result = convert(ln, result, length);
	return (result);
}
