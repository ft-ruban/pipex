/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:00:40 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/11 09:52:49 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c < 'A' || c > 'Z')
		return (c);
	else
		return (c + 32);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 'A';
	printf("%c", c);
	printf("%c",ft_tolower(c));
	return (0);
}
*/