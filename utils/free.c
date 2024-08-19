/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:26:50 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 12:29:06 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_xpm_ptr(t_image *image, t_prog *data)
{
	if (image->xpm_ptr)
		mlx_destroy_image(data->mlx_ptr, image->xpm_ptr);
}

void	free_all(t_prog *data)
{
	del_data(data);
	free_xpm_ptr(&(data->no_wall), data);
	free_xpm_ptr(&(data->we_wall), data);
	free_xpm_ptr(&(data->so_wall), data);
	free_xpm_ptr(&(data->ea_wall), data);
	if (data->no_wall.filename)
		free(data->no_wall.filename);
	if (data->so_wall.filename)
		free(data->so_wall.filename);
	if (data->we_wall.filename)
		free(data->we_wall.filename);
	if (data->ea_wall.filename)
		free(data->ea_wall.filename);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
