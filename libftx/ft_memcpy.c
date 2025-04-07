/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:59:27 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/11 09:56:51 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_char;
	char	*src_char;
	int		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest_char = (char *)dest;
	src_char = (char *)src;
	while (n != 0)
	{
		dest_char[i] = src_char[i];
		n--;
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main (void)
{
	const char	src[42] = "joj";
	int			number;
	int			i;

	char string [42] = "forty-two";
	number = 3;
	i = 0;
	ft_memcpy(string, src, number);
	while (string [i] != '\0')
	{
		printf("%c",string [i]);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_char;
	char	*src_char;
	int		i;

	i = 0;
	dest_char = (char *)dest;
	src_char = (char *)src;
	while (n != 0)
	{
		dest_char[i] = src_char[i];
		n--;
		i++;
	}
	return (dest);
}*/
