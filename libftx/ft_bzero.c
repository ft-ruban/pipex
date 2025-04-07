/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:59:27 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/11 09:45:06 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

/*
#include <stdio.h>
#include <string.h>

int	main (void)
{
	int	number;
	int	i;

	char string [42] = "forty-two";
	number = 5;
	i = 0;
	ft_bzero(string, number);
	while (i != 10)
	{
		printf("%c",string [i]);
		i++;
	}
	return (0);
}
*/