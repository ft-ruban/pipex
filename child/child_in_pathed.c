/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_in_pathed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:32:36 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/17 16:36:12 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void child_in_pathed_exec_failed(char **split_args, char **split_result, char *path, char **result)
{
    int i;
    
    free_double_array(split_result,split_args, path, NULL);
    i = 0;
    while(result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);
    exit(-1);
}

void child_in_pathed_exec_final(char **split_args, char **split_result, char *path, int *fd)
{
    char **result;
    int i;
    
    i = 0;
    while (split_args[i])
    i++;
    result = ft_split(split_args[i-1], ' ');
    if (!result)
    {
        free_double_array(split_result,split_args, path, NULL);
        child_error(-42, fd);
    }
    ft_printfd("result = %s\n", result[0]); //TORM
    ft_printfd("result1 = %s\n", result[1]); //TORM
    ft_printfd("result2 = %s\n", result[2]); //TORM
    execve(split_result[0], result, NULL);
    child_in_pathed_exec_failed(split_args, split_result, path, result); //OKKK
}

void child_in_pathed_exec(char *cmd, int *fd, char *path)
{
    char **split_result;
    char **split_args;

    path = ft_strdup(cmd);
    if(!path)
        child_error(-42, fd);
    split_result = ft_split(path, ' '); //FAIT
    if (!split_result)
    {
        free(path);
        child_error(-42, fd);
    }
    ft_printfd("PATHQQQQQQQQQQQQQQQu = %s\n", split_result[0]);
    ft_printfd("CMD = %s\n", cmd);
    split_args = ft_split(cmd, '/');
    if(!split_args)
    {
        free_double_array(split_result,NULL, path, NULL);
        child_error(-42, fd);
    }
    child_in_pathed_exec_final(split_args, split_result, path, fd);
}