/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:31:42 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/08 09:42:05 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

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

int is_already_pathed(char *cmd)
{
        printf("cmd : %s\n", cmd); //TODL
        if (!access(cmd, X_OK))
            return (0);
        else 
            return (1);
}
