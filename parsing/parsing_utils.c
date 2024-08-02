/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:37:23 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/02 16:13:14 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_errors(char *message, int error_status)
{
	printf("%s\n", message);
	exit(error_status);
}

int	ft_count_args(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}
