/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:39 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/10 17:56:05 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[42] = "forty-two";
	int c = 't';
	//int i = 0;

	printf("%s\n",ft_strchr(s,c));
	while(s[i] != '\0')
	{
		printf("%c\n",s[i]);
		i++;
	}
	*/
//}