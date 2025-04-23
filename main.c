/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:02:13 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/23 16:59:56 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

// Main that would check if the argc are valids
// then once everything is fine we launch ft_pipex
// and save the return value
// to return different values depending of what happened inside.

int	begin_parsing(int argc, char **env, int i, int path_found)
{
	if (argc != 5)
		return (1);
	if (!env)
		return (1);
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			path_found = 1;
			break ;
		}
		i++;
	}
	if (!path_found)
		exit(1);
	return (0);
}

int	main(int argc, char *argv[], char **env)
{
	int	return_value_pipex;

	if (begin_parsing(argc, env, 0, 0))
		exit(1);
	return_value_pipex = ft_pipex(argv, env);
	if (return_value_pipex == 127)
		ft_printfd("command not found: %s\n", argv[3]);
	if (return_value_pipex == 255)
		return (127);
	return (return_value_pipex);
}
