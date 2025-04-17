/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/17 11:52:09 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int ft_check_args_final(char *argv[], char *path, int i)
{
    i = 0; //TORM
    if(ft_check_cmd (argv[3], path, 0, NULL))
    {
        free (path);
        return (127);
    }
    free(path);
    if(ft_check_outfile (argv[4])) //check if it can fail
        return (1);
    return (0);
}
int ft_check_args(char *argv[], char **env, int i)
{
    char *path;
    
    path = NULL;
    if(ft_check_infile(argv[1]))
        return (2);
    while (env[i] || !path)
    {
        if (!ft_strncmp(env[i], "PATH=", 5))
        {
            printf("env[i] : %s\n",env[i]); //TORM
            path = ft_strdup(env[i]);
            if (!path)
                return(2); //check right error
            break;
        }
        i++;
    }
    printf("argv[2] : %s\n",argv[2]); //TORM
    if(ft_check_cmd (argv[2], path, 0, NULL))
    {
        free (path);
        return (3);
    }
    return (ft_check_args_final(argv,path, 0));
}
