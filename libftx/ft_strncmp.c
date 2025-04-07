/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:18:19 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/08 20:25:54 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n != 0 && *s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[42] = "test";
	char	s2[42] = "testss";
	size_t	n;
	char	s3[42] = "abcdef";
	char	s4[42] = "abcdefghijklmnop";

	n = 7;
	printf("%d\n",ft_strncmp(s1, s2, n));
	printf("%d", strncmp(s3,s4,n));
}
*/

/*
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (*s1 == 0 && *s2 == 0)
		return (0);
	else if (*s1 == 0)
		return (-1);
	else if (*s2 == 0)
		return (1);
	while (n != 0 && *s1 && (*s1 == *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	if (*s1 != *s2 && *s1 != 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	else
		return (0);
}


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n != 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	if (n >= 0)
	{
		//if (*s1 != *s2)
			return (*s1 - *s2);
	}
	return (0);
}*/
