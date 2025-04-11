/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:30:33 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/11 08:49:12 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

//check if the infile does exist and if there is the right perm to read.
//may have to check the code error but otherwise it is working.

int ft_check_infile (char *argv)
{
    int fd;
    
    fd = open(argv,O_RDONLY);
    if (fd == -1)
    {
        ft_printf("error opening %s, make sure it does exist\n", argv); //TORM
        ft_printf("or if you have the permissions\n"); //TODO check for error code  with original pipe here.
        return (1);
    }
    else
    {
        close(fd);
        return(0);
    }
}

int ft_check_outfile (char *argv)
{
    int fd;
    
    fd = open(argv ,O_CREAT | O_RDONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
        ft_printf("error opening %s, make sure it does exist\n", argv);
        ft_printf("or if you have the permissions\n"); //TODO check for error code  with original pipe here.
        return (1);
    }
    else
    {
        close(fd);
        return(0);
    } 
}