/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:10:20 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/10 13:43:09 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[42] = "forty-two";

	printf("origin : %zu\n ft : %zu\n",strlen(str), ft_strlen(str));
	return(0);
}
*/
