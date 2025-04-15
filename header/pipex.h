/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:49:25 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/15 16:49:46 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libftx/libft.h"
# include <unistd.h>
# include <fcntl.h>
#include <sys/wait.h>
//# include <unistd.h>
//# include <stdio.h>
//# include <sys/types.h>
# define TRUE 1
# define FALSE 0

int        main(int argc, char *argv[], char **env);

int ft_check_args(char *argv[], char **env, int error);
int ft_check_infile (char *argv);
int ft_check_outfile (char *argv);
int ft_check_cmd (char *cmd, char *path, int i, char **cmd_separated_flags);

int     ft_pipex(char **argv, char **env);

int is_already_pathed(char *cmd, char **result_split);

int free_check_args(char *path, char **cmd, int i, int error);

void child_in(char **argv, char **env, int flag_open, int *fd);
void child_error(int infile, int *fd);

void exit_function(int error_code, char **argv);

#endif