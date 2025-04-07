/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:59:27 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/08 19:12:17 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_char;
	char	*src_char;

	dest_char = (char *)dest;
	src_char = (char *)src;
	if (dest_char < src_char)
	{
		while (n--)
			*dest_char++ = *src_char++;
	}
	else if (dest_char > src_char)
	{
		dest_char += n;
		src_char += n;
		while (n--)
			*--dest_char = *--src_char;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main (void)
{
	char string [50] = "Hello, world!";
	ft_memmove(string + 7, string, 6);
	printf("%s\n",string);
	const char src[42] = "123";
	int number = 1;
	int	i = 0;
	ft_memmove(string, src, number);

	while (string [i] != '\0')
	{
		printf("%c",string [i]);
		i++;
	}
	return (0);

}*/