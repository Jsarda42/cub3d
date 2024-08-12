/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:10:25 by juliensarda       #+#    #+#             */
/*   Updated: 2024/08/12 14:29:05 by jsarda           ###   ########.fr       */
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
	printf("filename in init = %s\n", data->no_wall.filename);
	printf("filename in init= %s\n", data->so_wall.filename);
	printf("filename in init= %s\n", data->we_wall.filename);
	printf("filename in init= %s\n", data->ea_wall.filename);
	if (!data->no_wall.xpm_ptr)
		file_to_img(&(data->no_wall), data, data->no_wall.filename);
	if (!data->so_wall.xpm_ptr)
		file_to_img(&(data->so_wall), data, data->so_wall.filename);
	if (!data->we_wall.xpm_ptr)
		file_to_img(&(data->we_wall), data, data->we_wall.filename);
	if (!data->ea_wall.xpm_ptr)
		file_to_img(&(data->ea_wall), data, data->ea_wall.filename);
}

void	init_textures(t_prog *data)
{
	init_walls(data);
}
