/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:33:54 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/09 11:01:05 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*it1;
	unsigned char	*it2;

	it1 = (unsigned char *)s1;
	it2 = (unsigned char *)s2;
	while (n != 0 && *it1 == *it2)
	{
		it1++;
		it2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((int)(*it1) - (int)(*it2));
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[42] = "\xff\xaa\xde\xffMACOSX\xff";
	char	s2[42] = "\xff\xaa\xde\x02";
	size_t	n;

	n = 8;
	//printf("%d\n",ft_memcmp(s1,s2,n));
	return (0);
}
*/
