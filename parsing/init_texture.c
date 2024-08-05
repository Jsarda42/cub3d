/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:10:25 by juliensarda       #+#    #+#             */
/*   Updated: 2024/08/05 14:59:45 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	file_to_img(t_image *image, t_prog *data)
{
}

void	init_walls(t_prog *data, char **cardinal, int i)
{
	cardinal[1][ft_strlen(cardinal[1]) - 1] = '\0';
	if (i == 0 && strcmp(cardinal[0], "NO") == 0)
	{
		data->no_wall.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
				cardinal[1], &data->no_wall.w, &data->no_wall.h);
		if (!data->no_wall.xpm_ptr)
			ft_errors(data, "Error initialising xpm to images", 2);
	}
	else if (i == 1 && strcmp(cardinal[0], "SO") == 0)
	{
		data->so_wall.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
				cardinal[1], &data->so_wall.w, &data->so_wall.h);
		if (!data->so_wall.xpm_ptr)
			ft_errors(data, "Error initialising xpm to images", 2);
	}
	else if (i == 2 && strcmp(cardinal[0], "WE") == 0)
	{
		data->we_wall.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
				cardinal[1], &data->we_wall.w, &data->we_wall.h);
		if (!data->we_wall.xpm_ptr)
			ft_errors(data, "Error initialising xpm to images", 2);
	}
	else if (i == 3 && strcmp(cardinal[0], "EA") == 0)
	{
		data->ea_wall.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
				cardinal[1], &data->ea_wall.w, &data->ea_wall.h);
		if (!data->ea_wall.xpm_ptr)
			ft_errors(data, "Error initialising xpm to images", 2);
	}
}

void	init_texture(t_prog *data)
{
	char	**map;
	char	**cardinal;
	int		i;

	i = 0;
	map = data->map_data.map_str;
	while (i < 4)
	{
		cardinal = ft_split(map[i], ' ');
		if (ft_count_args(cardinal) != 2)
		{
			free_split(cardinal);
			ft_errors(data, "Wrong cardinal identifier", -42);
		}
		init_walls(data, cardinal, i);
		free_split(cardinal);
		i++;
	}
}
