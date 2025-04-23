/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:49:25 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/23 17:16:27 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libftx/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

int		main(int argc, char *argv[], char **env);
int		ft_pipex(char **argv, char **env);

// child_in.c
void	child_in(char **argv, char **env, int *fd);
void	child_in_exec(char *cmd, char **env, int *fd);

// child_in_pathed.c
void	childs_pathed_exec(char *cmd, int *fd, char *path);
void	childs_pathed_exec_final(char **split_args, char **split_result,
			char *path, int *fd);
void	childs_pathed_exec_failed(char **split_args, char **split_result,
			char *path, char **result);

// child_out.c
void	child_out(char **argv, char **env, int *fd);

// child_utils.c
void	child_error(int infile, int *fd, int error, char *cmd);
char	*free_arrays(char **one, char **two, char *three, char *four);
char	*path_finder(char **env, char *cmd, char *path);
char	*prepare_path_resolution(char *path, char *cmd);
char	*search_executable_in_paths(char **result_split, char *buff, char *cmd,
			char *full_path);

#endif