/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:10:28 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/25 13:07:40 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

char	*get_next_line(int fd);
//size_t	ft_strlen(const char *str);
//void	*ft_calloc(size_t element_count, size_t element_size);
//char	*ft_strchr(const char *s, int c);
//char	*ft_strjoin(char *s1, char *s2);

#endif
