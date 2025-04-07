/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:59:27 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/08 19:13:34 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main (void)
{
	int	character;
	int	number;
	int	i;

	char string [42] = "forty-two";
	character = '4';
	number = 5;
	i = 0;
	ft_memset(string, character, number);
	while (string [i] != '\0')
	{
		printf("%c",string [i]);
		i++;
	}
	return (0);
}
*/