/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_to_int_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:42:09 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/23 16:55:41 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	argv_to_int_array(char *argv[], int argc, int **array_a)
{
	int	i;
	int	a;

	i = 1;
	a = 0;
	(void)argc;
	*array_a = malloc((argc - 1) * sizeof(int));
	if (!*array_a)
		return (1);
	while (argv[i] != 0)
	{
		(*array_a)[a] = ft_atoi(argv[i]);
		a++;
		i++;
	}
	return (0);
}
