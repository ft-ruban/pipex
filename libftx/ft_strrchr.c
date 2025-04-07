/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:39 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/11 09:15:21 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	while (i >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		i--;
	}
	return (0);
}

/*

#include <s.h>
#include <stdio.h>

int	main(void)
{
	const char	s[42] = "forty-two";
	int			c;

	c = 't';
	// int i = 0;
	printf("%s\n", ft_strrchr(s, c));
}
*/