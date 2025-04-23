/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:36:13 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/23 17:00:32 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

// TODO IF NO MODIFICATION CREATE CHILD_EXEC INSTEAD
void	child_out_exec(char *cmd, char **env, int *fd)
{
	char	*path;
	char	**args;
	char	*path_param;

	path_param = NULL;
	if (!ft_strchr(cmd, '/'))
	{
		path = path_finder(env, cmd, path_param);
		if (path == NULL)
			child_error(-42, fd, 1, cmd);
		args = ft_split(cmd, ' ');
		if (!args)
		{
			free(path);
			child_error(-42, fd, 0, cmd);
		}
		execve(path, args, env);
		free_arrays(args, NULL, path, NULL);
		exit(-1);
	}
	else
	{
		path = NULL;
		childs_pathed_exec(cmd, fd, path);
	}
}

void	child_out(char **argv, char **env, int *fd)
{
	int	outfile;

	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		child_error(-1, fd, 0, NULL);
	close(fd[0]);
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		ft_printfd("permission denied: %s\n", argv[4]);
		child_error(outfile, fd, 0, NULL);
	}
	close(outfile);
	child_out_exec(argv[3], env, fd);
}
