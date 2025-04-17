/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:31:42 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/17 16:38:51 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

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
//TOMV into check_cmd?
int check_is_already_pathed(char *cmd, char **result_split) 
{
        printf("cmd : %s\n", cmd); //TODL
        if (!access(cmd, X_OK))
        {
            free(cmd);
            return(free_check_args(NULL, result_split, 0, FALSE));
        }            
        else
        {
            free(cmd);
            return(free_check_args(NULL, result_split, 0, TRUE));        
        }
}
