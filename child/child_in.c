/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:27:36 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/23 15:26:12 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

// Find the path if it is not already pathed
// and execve with the path we found and
// hold in a variable the cmd + their respective flags
// if execve everything would be handled
// if the user send us a premade path then we go to
// child_in_pathed_exec

// parse_cmd
void	child_in_exec(char *cmd, char **env, int *fd)
{
	char	*path;
	char	**separated_cmd_flags;

	if (!ft_strchr(cmd, '/'))
	{
		path = path_finder(env, cmd, NULL);
		if (path == NULL)
			child_error(-42, fd, 1, cmd);
		separated_cmd_flags = ft_split(cmd, ' ');
		if (!separated_cmd_flags)
		{
			free(path);
			child_error(-42, fd, 0, cmd);
		}
		execve(path, separated_cmd_flags, env);
		free_arrays(separated_cmd_flags, NULL, path, NULL);
		exit(-1);
	}
	else
		childs_pathed_exec(cmd, fd, NULL);
}

// Close pipe[0] because we do not need it here obviously
// open the infile, if it fail we check the reason why it did
// to send a message depending of the situation to mimic the
// real deal if it work we dup the entrance pipe + our infile
// then close them and get to the next step child_in_exec
// TORM tomorrow we check child_in_exec :>

void	child_in(char **argv, char **env, int *fd)
{
	int	infile;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		if (access(argv[1], F_OK))
			ft_printfd("no such file or directory: %s\n", argv[1]);
		else
			ft_printfd("permission denied: %s\n", argv[1]);
		child_error(infile, fd, 0, NULL);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		child_error(infile, fd, 0, NULL);
	if (dup2(infile, STDIN_FILENO) == -1)
		child_error(infile, fd, 0, NULL);
	close(fd[1]);
	close(infile);
	child_in_exec(argv[2], env, fd);
}
