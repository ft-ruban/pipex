/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:27:36 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/17 11:59:52 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

//SEEM CLEAN (LEAKS)

char *find_path_loop(char **result_split, char *buff, char *cmd, char *full_path)
{
    int i;
    
    i = 0;
    while (result_split[i])
    {
        buff = ft_strjoin(result_split[i], "/"); 
        if(!buff)
            return(free_double_array(NULL,result_split, cmd, NULL));
        ft_printfd("CMD = %s\n",cmd);
        ft_printfd("BUFF VITE = %s\n",buff);
        full_path = ft_strjoin(buff, cmd); //fait
        if(!full_path)
            return(free_double_array(NULL,result_split, cmd, buff));
        ft_printfd("FUL_PATH = %s\n",full_path);
        free(buff);  
        if(!access(full_path, X_OK))
        {
            free_double_array(result_split, NULL, cmd, NULL);
            ft_printfd("FUL_PATHsucc = %s\n",full_path);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    exit(-1);
}
//Checked leaks no leaks 
char *find_path(char *path, char *cmd)
{
    char **result_split;
    int i;
    char **cmd_separated_flags;
    char *buff;

    i = 0;
     while ((cmd[i] >= 9 && cmd[i] <= 13) || cmd[i] == 32)
         i++;
    result_split = ft_split(path, ':');
    if (!result_split)
        return(NULL);
    cmd_separated_flags = ft_split(cmd,' ');
    if (!cmd_separated_flags || !result_split)
        return(free_double_array(result_split,NULL, NULL, NULL));
    buff = ft_strdup(cmd_separated_flags[0]);
    if (!buff)
        return(free_double_array(result_split,cmd_separated_flags, NULL, NULL));

    free_double_array(NULL,cmd_separated_flags, NULL, NULL);
    return(find_path_loop(result_split, NULL, buff, NULL));
}

void child_in_exec_pathed(char *cmd, char **env, int *fd, char *path)
{
    char **split_result;
    char **split_args;
    int i;

    i = 0;
    env = NULL;
    path = ft_strdup(cmd);
    if(!path)
        child_error(-42, fd);
    split_result = ft_split(path, ' '); //check si quelqu'un met des espaces partouts + leaks
    ft_printfd("PATHQQQQQQQQQQQQQQQu = %s\n", split_result[0]);
    ft_printfd("CMD = %s\n", cmd);
    split_args = ft_split(cmd, '/'); //secure leaks
    while (split_args[i])
        i++;
    split_args = ft_split(split_args[i-1], ' ');
    ft_printfd("SPLIT_ARGS = %s\n", split_args[1]);
    execve(split_result[0], split_args, NULL);
    ft_printfd("IT DOESNT WORK HWDHDHDWH\n");
}

void child_in_exec(char *cmd, char **env, int *fd)
{
    char *path;
    char **args;

    if (!ft_strchr(cmd,'/'))
    {
        path = return_path(env, cmd); //WIP
        if (path == NULL)
            child_error(-42, fd);
    }
    else
    {
        path = NULL;
        child_in_exec_pathed(cmd,env,fd,path);
    }
    ft_printfd("PATHQQQQQQQQQQQQQQQ = %s\n", path);
    args = ft_split(cmd,' '); //PROTECT
    ft_printfd("THEENDOFCHILDIN\n\n\n\n\n\n",args[2]);
    execve(path, args, NULL);
    ft_printfd("IT FAILED\n");
    exit(-1);
}


//HAVE BEEN VERIFIED NO MALLOC PROBLEMS yeepee

void    child_in(char **argv, char **env, int *fd)
{
    int infile;

    ft_printfd("Child IN\n");
    close(fd[0]);
    infile = -42;
    infile = open(argv[1], O_RDONLY);
    if (infile == -1)
        child_error(infile, fd);
    if(dup2(fd[1], STDOUT_FILENO) == -1) 
        child_error(infile, fd);
    if(dup2(infile, STDIN_FILENO) == -1)
        child_error(infile, fd);  
    close(fd[1]);
    close(infile); 
    child_in_exec(argv[2], env, fd);
}
