/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:47:22 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 17:47:55 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	convert_ascii_to_double(int i, const char *nptr, int negative,
		double result)
{
	double	decimal_divisor;
	int		is_fractional;

	decimal_divisor = 1.0;
	is_fractional = 0;
	while ((nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '.'
		|| nptr[i] == ',')
	{
		if (nptr[i] == '.' || nptr[i] == ',')
		{
			if (is_fractional)
				break ;
			is_fractional = 1;
			i++;
			continue ;
		}
		result = result * 10 + (nptr[i] - '0');
		if (is_fractional)
			decimal_divisor *= 10.0;
		i++;
	}
	result = result / decimal_divisor;
	if (negative)
		result *= -1.0;
	return (result);
}

double	ft_atop(const char *nptr)
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
	return (convert_ascii_to_double(i, nptr, negative, 0.0));
}
