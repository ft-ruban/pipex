/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:02:13 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/08 11:46:34 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"





int main(int argc, char *argv[], char **env)
{
    //int          p_fd[2];
    //pid_t   pid;
    int error_code;
    if (argc != 5)
        exit_function(1, argv);
    error_code = (ft_check_args(argv, env, 0));
    if (error_code != 0)
        exit_function(error_code, argv);
    
    //TODO ft_init_pipex()
    //TODO if (ft_check_args() == 1)
    //TODO     exit_function(1);
    //TODO ft_parse_cmds()
    //TODO ft_parse_args()
    //TODO while (cmds)
    //TODO      ft_exec()
    //TODO ft_cleanup
    ft_printf("Program worked :>\n");
    return(0);
}

/*
- parent : check arg (le nombre ? acces infile ? access outfile ? path cmd1 ? path cmd2 ?)
- créer un pipe
- parent : fork pid1 (infile cmd1)
    enfant : execve(cmd1)
- parent : fork pid2
    enfant : execve(cmd2)
- parent : waitpid
*/