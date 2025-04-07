/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/07 16:40:09 by ldevoude         ###   ########lyon.fr   */
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

int ft_check_cmd_one (char *cmd, char *path)
{
    char **result_split;
    char *full_path;
    int i;
    char *buff;
    
    i = 0;
    result_split = ft_split(path, ':');
    if (!result_split)
        return 1;
    while (result_split[i])
    {
        buff = ft_strjoin(result_split[i], "/");
        full_path = ft_strjoin(buff, cmd);
        free(buff);
        if(!access(full_path, X_OK))
        {
            free(result_split);
            printf("FULL_PATH = %s\n",full_path);
            free(full_path); 
            return (0);
        }
        free(full_path);
        i++;
    }
    i = 0; 
    while(result_split[i])
    {
        free(result_split[i]);
        i++;
    }
    free(result_split);
    return (1);
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
     if (!ft_strncmp(env[i], "PATH=", 4))  //5?
     {
        path = ft_strdup(env[i]);
        break;
     }
     i++;
    }
    cmd = ft_split(argv[2], ' ');
    if(ft_check_cmd_one (cmd[0], path))
    {
        return (1);
    }
    //ft_check_cmd_two (argc, argv[4]);
    //ft_check_outfile (argc, argv[5])
    i = 0;
    while (cmd[i])
    {
        free(cmd[i]);
        i++;
    }
    free(cmd);
    free (path);
    return (0);
}
