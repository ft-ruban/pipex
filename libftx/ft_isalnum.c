/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:10:20 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/08 18:40:23 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z'))
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

	c = 'a';
	printf("origin : %d\n ft : %d\n",isalnum(c), ft_isalnum(c));
	return(0);
}
*/
