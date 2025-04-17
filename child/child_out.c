/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:36:13 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/17 11:43:54 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void child_out(char **argv, char **env, int *fd)
{
    int outfile;

    env = NULL;
    ft_printfd("Child OUT\n");
    close(fd[1]);
    outfile = -42;
    outfile = open(argv[4], O_RDONLY);
    if (outfile == -1)
        child_error(outfile, fd);//exit(-1); //TODO check if I have to free anything
    if(dup2(fd[0], STDOUT_FILENO) == -1)
        child_error(outfile, fd);
    if(dup2(outfile, STDIN_FILENO) == -1)
        child_error(outfile, fd);  
    close(fd[0]);
    close(outfile); //do exec close it?
    //child_in_exec(argv[2], env, fd);
}