/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:59:11 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/10 17:50:16 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	length;

	length = ft_strlen(s);
	write(fd, s, length);
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
	ft_putstr_fd(s, handle);
	printf("Success!");
	close le file
	return (0);
}
*/
