/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:00:40 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/25 09:59:51 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strtoupper(char *convert)
{
	int	i;

	i = 0;
	while (convert[i] != 0)
	{
		if (convert[i] >= 'a' && convert[i] <= 'z')
			convert[i] -= 32;
		i++;
	}
	return (convert);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 97;
	printf("%c", c);
	printf("%c",ft_toupper(c));
	return (0);
}
*/
