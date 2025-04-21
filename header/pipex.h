/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:49:25 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/21 14:27:40 by ldevoude         ###   ########lyon.fr   */
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
int        ft_pipex(char **argv, char **env);

void       exit_function(int error_code, char **argv);

//PARSING
int ft_check_args(char *argv[], char **env, int error);
int ft_check_infile (char **argv);
int ft_check_outfile (char *argv);
int ft_check_cmd (char *cmd, char *path, int i, char **cmd_separated_flags);
int check_is_already_pathed(char *cmd, char **result_split);
int free_check_args(char *path, char **cmd, int i, int error);

//child_in.c
void child_in(char **argv, char **env, int *fd);
void child_in_exec(char *cmd, char **env, int *fd);
char *find_path(char *path, char *cmd);
char *find_path_loop(char **result_split, char *buff, char *cmd, char *full_path);

//child_in_pathed.c
void child_in_pathed_exec(char *cmd, int *fd, char *path);
void child_in_pathed_exec_final(char **split_args, char **split_result, char *path, int *fd);
void child_in_pathed_exec_failed(char **split_args, char **split_result, char *path, char **result);

//child_out.c
void child_out(char **argv, char **env, int *fd);

//child_utils.c
void child_error(int infile, int *fd);
char *free_double_array(char **one, char **two, char *three, char *four);
char *return_path(char **env, char *cmd, char *path);



#endif