/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:01:03 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/06 16:09:46 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_window(t_prog *data)
{
	int	screen_height;
	int	screen_width;

	screen_height = 0;
	screen_width = 0;
	mlx_get_screen_size(data->mlx_ptr, &screen_width, &screen_height);
	data->win_ptr = mlx_new_window(data->mlx_ptr, screen_width, screen_height, "cude3D");
	if (!data->win_ptr)
		ft_errors(data, "Failed to create window", -41);
}
