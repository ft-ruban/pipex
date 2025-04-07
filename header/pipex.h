/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:49:25 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/07 14:45:22 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libftx/libft.h"
# include <fcntl.h>
//# include <unistd.h>
//# include <stdio.h>
//# include <sys/types.h>
# define TRUE 1
# define FALSE 0

int        main(int argc, char *argv[], char **env);

int ft_check_args(int argc, char *argv[], char **env);
int ft_check_infile (int argc, char *argv);

void       exit_function(int error_code);

#endif