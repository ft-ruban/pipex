/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:22:53 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/07 12:23:04 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

void    exit_function(int error_code)
{
    if (error_code == 1)
        ft_printfd("./pipex infile ""ls -l" "wc -l"" outfile");
    exit(error_code);
}