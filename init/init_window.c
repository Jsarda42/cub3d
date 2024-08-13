/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:01:03 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/12 11:26:53 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_window(t_prog *data)
{
	mlx_get_screen_size(data->mlx_ptr, &data->S_W, &data->S_H);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->S_W, data->S_H,
			"cude3D");
	if (!data->win_ptr)
		ft_errors(data, "Failed to create window", -41);
}
