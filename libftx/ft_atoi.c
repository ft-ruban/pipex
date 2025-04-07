/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:26:14 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/11 09:44:25 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	convert_ascii_to_int(int i, const char *nptr, int negative)
{
	long	result;

	result = 0;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		result += nptr[i] - 48;
		if (nptr[i + 1] <= '9' && nptr[i + 1] >= '0')
			result *= 10;
		if (result == 2147483647)
			return (2147483647);
		if (result == 2147483648 && negative == TRUE)
			return (-2147483648);
		i++;
	}
	if (negative == TRUE)
		result *= -1;
	return ((int)result);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	negative;

	negative = FALSE;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative = TRUE;
		i++;
	}
	return (convert_ascii_to_int(i, nptr, negative));
}
/*
#include <stdio.h>

int	main(void)
{
	char	nptr[42] = "-420";

	printf("%d",ft_atoi(nptr));
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		negative;

	negative = FALSE;
	result = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative = TRUE;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		result += nptr[i] - 48;
		if (nptr[i + 1] <= '9' && nptr[i + 1] >= '0')
			result *= 10;
		i++;
	}
	if (negative == TRUE)
		result *= -1;
	return (result);
}*/
