/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:31:59 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/10 16:50:26 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

//will check the cmd to see if it does exist as an absolute
//path or as a simple command, if it does return 0 else 1
//no leaks and all cases seems to be working with it.

int ft_check_cmd_compare (char **result_split, char *buff, char *cmd, char *full_path)
{
    int i;

    i = 0;
    while (result_split[i])
    {
        buff = ft_strjoin(result_split[i], "/");
        full_path = ft_strjoin(buff, cmd);
        if(!full_path)
            return(free_check_args(buff,result_split,0, TRUE));
        free(buff);   
        if(!access(full_path, X_OK))
        {
            free(cmd);
            return(free_check_args(full_path, result_split, 0, FALSE));
        }
        free(full_path);
        i++;
    }
    free(cmd);
    return (free_check_args(NULL, result_split, 0, TRUE));
    //return (0);
}

int ft_check_cmd (char *cmd, char *path, int i)
{
    char **result_split;
    char **cmd_separated_flags;
    char *buff;
    
    cmd_separated_flags = NULL;
    if (ft_strlen(cmd) == 0)
        return (1);
    while ((cmd[i] >= 9 && cmd[i] <= 13) || cmd[i] == 32)
		i++;
    if (cmd[i] == '\0')
        return (1);
    if (ft_strchr(cmd,'/'))
        return(is_already_pathed(cmd));
    result_split = ft_split(path, ':');
    if (!result_split)
        return (1);
    cmd_separated_flags = ft_split(cmd,' ');
    printf("cmd_separe %s\n", cmd_separated_flags[0]);
    buff = ft_strdup(cmd_separated_flags[0]);
    i = 0;
    while(cmd_separated_flags[i])
    {
        free(cmd_separated_flags[i]);
        i++;
    }
    free(cmd_separated_flags);
    return (ft_check_cmd_compare (result_split, NULL, buff, NULL));
}



