/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:00:40 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/08 20:22:25 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c < 'a' || c > 'z')
		return (c);
	else
		return (c - 32);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 97;
	printf("%c", c);
	printf("%c",ft_toupper(c));
	return (0);
}
*/