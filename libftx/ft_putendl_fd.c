/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:59:11 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/08 19:16:41 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	length;

	length = ft_strlen(s);
	write(fd, s, length);
	write(fd, "\n", 1);
	return ;
}
/*
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		handle;
	char	s[64] = "forty-two";

	handle = open("test.txt", O_WRONLY);
	ft_putendl_fd(s, handle);
	printf("Success!\n");
	return (0);
}
*/
