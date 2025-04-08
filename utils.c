/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:22:53 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/08 12:47:33 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

//TODO handle error to behave like the classic pipe
void    exit_function(int error_code, char **argv)
{
    if (error_code == 1)
        ft_printfd("./pipex infile ""ls -l" "wc -l"" outfile");
    if (error_code == 127)
    {
        ft_printfd("command not found: %s\n", argv[3]);
        exit(127);
    }
    ft_printf("error_code : %d \n", error_code);
    exit(2);
}