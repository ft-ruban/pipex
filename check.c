/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/08 13:12:32 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

//check if the infile does exist and if there is the right perm to read.
//may have to check the code error but otherwise it is working.

int ft_check_infile (char *argv)
{
    int fd;
    
    fd = open(argv,O_RDONLY);
    if (fd == -1)
    {
        ft_printf("error opening %s, make sure it does exist\n", argv);
        ft_printf("or if you have the permissions\n"); //TODO check for error code  with original pipe here.
        return (1);
    }
    else
    {
        close(fd);
        return(0);
    }
}

//will check the cmd to see if it does exist as an absolute
//path or as a simple command, if it does return 0 else 1
//no leaks and all cases seems to be working with it.

int ft_check_cmd (char *cmd, char *path, int i)
{
    char **result_split;
    char *full_path;
    char *buff;
    
    if (ft_strlen(cmd) == 0)
        return (1);
    if (ft_strchr(cmd,'/'))
        return(is_already_pathed(cmd));
    result_split = ft_split(path, ':');
    if (!result_split)
        return (1);
    while (result_split[i])
    {
        buff = ft_strjoin(result_split[i], "/");
        full_path = ft_strjoin(buff, cmd);
        if(!full_path)
            return(free_check_args(buff,result_split,0, TRUE));
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
int ft_check_outfile (char *argv)
{
    int fd;
    
    fd = open(argv ,O_CREAT | O_RDONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
        ft_printf("error opening %s, make sure it does exist\n", argv);
        ft_printf("or if you have the permissions\n"); //TODO check for error code  with original pipe here.
        return (1);
    }
    else
    {
        close(fd);
        return(0);
    } 
}

int ft_check_args_final(char *argv[], char *path, int i)
{
    i = 0; //TORM
    if(ft_check_cmd (argv[3], path, 0))
    {
        free (path);
        return (127);
    }
    free(path);
    if(ft_check_outfile (argv[5])) //check if it can fail
    {
        //free (path);
        return (1);
    }
    return (0);
}
int ft_check_args(char *argv[], char **env, int i)
{
    char *path;
    
    path = NULL;
    if(ft_check_infile(argv[1]))
        return (1);
    while (env[i] || !path)
    {
     if (!ft_strncmp(env[i], "PATH=", 5))  //5?
     {
        printf("env[i] : %s\n",env[i]);
        path = ft_strdup(env[i]);
        break;
     }
     i++;
    }
    printf("argv[2] : %s\n",argv[2]);
    if(ft_check_cmd (argv[2], path, 0))
    {
        free (path);
        return (1);
    }
    return (ft_check_args_final(argv,path, 0));
    //ft_check_outfile (argc, argv[5])
    free(path);
    return (0);
}
