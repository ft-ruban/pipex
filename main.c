/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:02:13 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/07 14:21:48 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"





int main(int argc, char *argv[])
{
    //int          p_fd[2];
    //pid_t   pid;
    if (argc != 5)
        exit_function(1);
    if (ft_check_args(argc, argv) == 1)
        exit_function(1);
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