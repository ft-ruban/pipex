/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:10:20 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/08 18:43:04 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (42);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 135;
	printf("origin : %d\n ft : %d\n",isascii(c), ft_isascii(c));
	return(0);
}
*/