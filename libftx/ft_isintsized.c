/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isintsized.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:48:33 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/31 14:27:41 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_ascii_to_int(int i, const char *nptr, int negative)
{
	long	result;

	result = 0;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		if (result > 2147483648)
			return (1);
		result += nptr[i] - 48;
		if (nptr[i + 1] <= '9' && nptr[i + 1] >= '0')
			result *= 10;
		i++;
	}
	if (negative == TRUE)
		result *= -1;
	if (result > 2147483647 || result < -2147483648)
		return (1);
	else
		return (0);
}

int	ft_isintsized(const char *nptr)
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
