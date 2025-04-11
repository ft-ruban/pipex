/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:02:13 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/11 16:03:41 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

int     ft_pipex(char **argv, char **env)
{
    
}

//TODO? ft_init_pipex()
int main(int argc, char *argv[], char **env)
{
    //int          p_fd[2];
    //pid_t   pid;
    int error_code;
    if (argc != 5)  //TODO if (ft_check_args() == 1)
        exit_function(1, argv);
    error_code = (ft_check_args(argv, env, 0));  //TODO ft_parse_cmds()  //TODO ft_parse_args()
    if (error_code != 0)
        exit_function(error_code, argv);  //TODO     exit_function(1);
    ft_pipex(argv, env);
   
   
    
    //TODO while (cmds)
    //TODO      ft_exec()
    //TODO ft_cleanup
    ft_printf("Program worked :>\n");
    printf("CMD: %s\n",argv[2]);
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