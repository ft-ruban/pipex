/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:36:02 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/09 08:33:29 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	if (j == 0)
		return (ft_strdup(""));
	while (i < j && trim(set, s1[i]))
		i++;
	while (j > i && trim(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, j - i));
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[64] = "  \t \t \n   \n\n\n\t";
	char	s2[64] = "";

	char *ns =ft_strtrim(s1, s2);
	printf("%s", ns);
	return (0);
}
*/
