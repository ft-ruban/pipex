/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:10:09 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/07 14:33:46 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

int ft_check_infile (int argc, char *argv)
{
    argc = 0;
    int fd;
    fd = open(argv,O_RDONLY);
    if (fd == -1)
    {
        ft_printf("error opening %s, make sure it does exist\n", argv);
        return (1);
    }
    else
    {
        close(fd);
        return(0);
    }
}
// ft_check_cmd_one (int argc, char *argv)
// {
    
// }

int ft_check_args(int argc, char *argv[])
{
    argc = 0;
    if(ft_check_infile(argc, argv[1]))
        return (1);
    //ft_check_cmd_one (argc, argv[2]);
    //ft_check_cmd_two (argc, argv[4]);
    //ft_check_outfile (argc, argv[5])
    return (0);
}