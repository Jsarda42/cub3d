/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:10:25 by juliensarda       #+#    #+#             */
/*   Updated: 2024/08/08 11:00:00 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	file_to_img(t_image *image, t_prog *data, char *filename)
{
	image->xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, filename, &(image->w),
			&(image->h));
	if (!image->xpm_ptr)
		ft_errors(data, "Error uploading xpm to image", -42);
}

static void	init_walls(t_prog *data)
{
	if (!data->no_wall.xpm_ptr)
		file_to_img(&(data->no_wall), data, data->no_wall.filename);
	if (!data->so_wall.xpm_ptr)
		file_to_img(&(data->so_wall), data, data->so_wall.filename);
	if (!data->we_wall.xpm_ptr)
		file_to_img(&(data->we_wall), data, data->we_wall.filename);
	if (!data->ea_wall.xpm_ptr)
		file_to_img(&(data->ea_wall), data, data->ea_wall.filename);
}

static void init_player(t_prog * data)
{
	file_to_img(&(data->player_n), data, PLAYER_N);
	file_to_img(&(data->player_o), data, PLAYER_O);
	file_to_img(&(data->player_s), data, PLAYER_S);
	file_to_img(&(data->player_w), data, PLAYER_W);
}

void	init_textures(t_prog *data)
{
	init_walls(data);
	//init_player(data);
}
