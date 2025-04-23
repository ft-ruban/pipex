/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:13:37 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/23 16:44:45 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

// My pipex function that would summon all the necessary childs
// the parent is gonna wait here
// return the status of child 2 that would be used as an error signal

int	ft_pipex(char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	first_child;
	pid_t	second_child;
	int		status;
	int		status_two;

	status_two = -1;
	if (pipe(pipe_fd) == -1)
		exit(-1);
	first_child = fork();
	if (first_child == 0)
		child_in(argv, env, pipe_fd);
	second_child = fork();
	if (second_child == 0)
		child_out(argv, env, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (first_child != -1)
		waitpid(first_child, &status, 0);
	if (second_child != -1)
		waitpid(second_child, &status_two, 0);
	return (status_two >> 8);
}
