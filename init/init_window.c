/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:01:03 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 12:14:25 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_window(t_prog *data)
{
	mlx_get_screen_size(data->mlx_ptr, &data->s_w, &data->s_h);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->s_w, data->s_h,
			"cude3D");
	if (!data->win_ptr)
		ft_errors(data, "Failed to create window", -41);
}
