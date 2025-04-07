/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:42:27 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/23 17:06:47 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	total_size;

	if (nmemb != 0 && size != 0 && (nmemb > (size_t)-1 / size))
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == 0)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	int num_rats = 10;
	int *rats_list = 0;
	int i;


	rats_list = ft_calloc(num_rats, 8);

	while (num_rats--)
		printf("[%d]", rats_list[num_rats]);
}*/
