/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:37:23 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/05 14:50:19 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_all(t_prog *data)
{
	del_data(data);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	ft_errors(t_prog *data, char *message, int error_status)
{
	free_all(data);
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
