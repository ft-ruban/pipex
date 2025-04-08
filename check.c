/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/08 09:13:30 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

int ft_check_infile (int argc, char *argv)
{
    argc = 0;
    int fd;
    fd = open(argv,O_RDONLY);
    if (fd == -1)
    {
        ft_printf("error opening %s, make sure it does exist\n", argv);
        return (1);
    }
    else
    {
        close(fd);
        return(0);
    }
}

int ft_check_cmd_one (char *cmd, char *path, int i)
{
    char **result_split;
    char *full_path;
    char *buff;
    
    //check if we get a pathlike cmd
    if (ft_strchr(cmd,'/'))
    {
        printf("cmd : %s\n", cmd); //TODL
        if (!access(cmd, X_OK))
            return (0);
        else 
            return (1);
    }
    //split path to turn result_split into the return of split
    result_split = ft_split(path, ':');
    if (!result_split)
        return (1);

    while (result_split[i])
    {
        buff = ft_strjoin(result_split[i], "/");
        full_path = ft_strjoin(buff, cmd);
        free(buff);
        if(!access(full_path, X_OK))
        {
            printf("FULL_PATH = %s\n",full_path); //TODL
            return(free_check_args(full_path, result_split, 0, FALSE));
        }
        free(full_path);
        i++;
    }
    return (free_check_args(NULL, result_split, 0, TRUE));
}

int free_check_args(char *path, char **cmd, int i, int error)
{
    while (cmd[i])
    {
        free(cmd[i]);
        i++;
    }
    free(cmd);
    if(path)
        free(path);
    return (error);   
}
int ft_check_args(int argc, char *argv[], char **env)
{
    char *path;
    int i;
    char **cmd;
    
    argc = 0;
    i = 0;
    path = NULL;
    if(ft_check_infile(argc, argv[1]))
        return (1);
    while (env[i] || !path)
    {
     if (!ft_strncmp(env[i], "PATH=", 5))  //5?
     {
        path = ft_strdup(env[i]);
        break;
     }
     i++;
    }
    cmd = ft_split(argv[2], ' ');
    if(ft_check_cmd_one (cmd[0], path, 0))
        return (free_check_args(path, cmd, 0, TRUE));
    //ft_check_cmd_two (argc, argv[4]);
    //ft_check_outfile (argc, argv[5])
    return (free_check_args(path, cmd, 0, FALSE));
}
