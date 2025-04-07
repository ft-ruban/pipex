/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:59:16 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/11 09:51:20 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*error_malloc(char *ptr, char const *s)
{
	if (s == NULL)
		return (NULL);
	ptr = malloc(sizeof(char) * 1);
	if (!ptr)
		return (NULL);
	ptr[0] = 0;
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	if (!s || !*s || start >= ft_strlen(s))
		return (error_malloc(ptr, s));
	i = 0;
	if (ft_strlen(s) - start < len)
		ptr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (len-- > 0 && s[start])
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*s = "tripouille";
// 	int		start;
// 	size_t	len;
// 	char	*result;

// 	start = 3;
// 	len = 5;
// 	//result = malloc(5);
// 	result = ft_substr(s, start, len);
// //	while (result)
// 	// {
// 	if (result)
// 		printf("%s\n", result);
// //		result++;
// 	// }
// 	free(result);
// }

// s = "Hel|lo |world!"
// ft_substr(s, 3 ,3)

// start + len <= strlen(s)
// 	start = s[3]
// 	end = start + len = s[start + len]
// len_sub = end - start + 1 (\0)

// if ( start + len > strlen(s))
// 	end = strlen(s + start)
