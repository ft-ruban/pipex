/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:22:13 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/11 09:30:24 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	size_t	test;

	test = len;
	n = ft_strlen(little);
	if (!little)
		return ((char *)big);
	if (n == 0)
		return ((char *)big);
	while (*big && len)
	{
		if (!ft_strncmp(big, little, n) && len >= ft_strlen(little))
		{
			if (ft_strlen(little) > test)
				return (NULL);
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
/*
#include <bsd/string.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	big[42] = "lolololola";
	char	little[42] = "lolola";
	size_t	len;

	len = 64;
	char* p;
	p = ft_strnstr(big,little,len);
	p = strnstr(((void*)0), "fake", 3);
if (p)
	{
		printf("String found\n");
		printf("First occurrence of string '%s' in '%s' is "
				"'%s'",
				little, big, p);
	}
	else
		printf("String not found\n");
	return (0);
}
*/