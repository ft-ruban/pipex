/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:12:48 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/08 19:14:27 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int handle = open("test.txt", O_WRONLY);
	//... You need to check the result here
	char c = 'b';
	ft_putchar_fd(c, handle);
	printf("Success!");

}*/
