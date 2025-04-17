/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:29:05 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/17 14:40:58 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char *return_path(char **env, char *cmd)
{
    int i;
    char *path;
    char *final_result;
    
    final_result = NULL;
    path = NULL;
    i = 0;
    while (env[i] || !path)
    {
        if(!ft_strncmp(env[i], "PATH=", 5))
        {
            path = ft_strdup(env[i]); //OK
            if (path == NULL)
                return (NULL);
            final_result = find_path(path, cmd);//WIP
            if (final_result == NULL)
            {
                free(path);
                return (NULL);
            }
            break;
        }
        i++;
    }
    return(final_result);
}

char *free_double_array(char **one, char **two, char *three, char *four)
{
    int i;

    i = 0;
    if (one)
    {
        while(one[i])
        {
            free(one[i]);
            i++;
        }
        free(one);
    }
    i = 0;
    if (two)
    {
        while(two[i])
        {
            free(two[i]);
            i++;
        }
        free(two);
    }
    if (three)
        free(three);
    if (four)
        free(four);
    return (NULL);
}

void    child_error(int infile, int *fd)
{
    if (infile >= 0)
        close(infile);
    if(fd[1])
        close(fd[1]);
    exit(-1);
}