/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:36:13 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/21 14:47:21 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

// char *find_path(char *path, char *cmd)
// {
//     char **result_split;
//     int i;
//     char **cmd_separated_flags;
//     char *buff;

//     i = 0;
//      while ((cmd[i] >= 9 && cmd[i] <= 13) || cmd[i] == 32)
//          i++;
//     result_split = ft_split(path, ':');
//     if (!result_split)
//         return(NULL);
//     cmd_separated_flags = ft_split(cmd,' ');
//     if (!cmd_separated_flags || !result_split)
//         return(free_double_array(result_split,NULL, NULL, NULL));
//     buff = ft_strdup(cmd_separated_flags[0]);
//     if (!buff)
//         return(free_double_array(result_split,cmd_separated_flags, NULL, NULL));

//     free_double_array(NULL,cmd_separated_flags, path, NULL);
//     return(find_path_loop(result_split, NULL, buff, NULL));
// }

//TODO IF NO MODIFICATION CREATE CHILD_EXEC INSTEAD
void child_out_exec(char *cmd, char **env, int *fd)
{
    char *path;
    char **args;
    char *path_param;

    path_param = NULL;
    if (!ft_strchr(cmd,'/'))
    {
        path = return_path(env, cmd, path_param); 
        if (path == NULL)
            child_error(-42, fd);
        ft_printfd("PATHQQQQQQQQQQQQQQQ = %s\n", path);
        args = ft_split(cmd,' '); //PROTECT
        if(!args)
        {
            free(path);
            child_error(-42, fd);
        }
        // ft_printfd("THEENDOFCHILDOUT\n\n\n\n\n\n",args[3]);
        execve(path, args, NULL);
        free_double_array(args,NULL, path, NULL);
        exit(-1);
    }
    else    
    {
        path = NULL;
        child_in_pathed_exec(cmd,fd,path);
    }
}

void child_out(char **argv, char **env, int *fd)
{
    int outfile;

    //env = NULL;
    ft_printfd("Child OUT\n");
    close(fd[1]);
    outfile = -42;
    outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (outfile == -1)
        child_error(outfile, fd);//exit(-1); //TODO check if I have to free anything
    if(dup2(fd[0], STDIN_FILENO) == -1)
        child_error(outfile, fd);
    if(dup2(outfile, STDOUT_FILENO) == -1)
        child_error(outfile, fd);  
    close(fd[0]);
    close(outfile); //do exec close it?
    child_out_exec(argv[3], env, fd);
}