/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:10:25 by juliensarda       #+#    #+#             */
/*   Updated: 2024/08/06 16:09:31 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static int	file_to_img(t_image *image, t_prog *data, char *filename)
{
	image->xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, filename, &(image->w),
			&(image->h));
	if (!image->xpm_ptr)
		return (1);
	return (0);
}

static int	init_walls(t_prog *data, char **cardinal, int i)
{
	cardinal[1][ft_strlen(cardinal[1]) - 1] = '\0';
	if (i == 0 && strcmp(cardinal[0], "NO") == 0)
		return (file_to_img(&(data->no_wall), data, cardinal[1]));
	else if (i == 1 && strcmp(cardinal[0], "SO") == 0)
		return (file_to_img(&(data->so_wall), data, cardinal[1]));
	else if (i == 2 && strcmp(cardinal[0], "WE") == 0)
		return (file_to_img(&(data->we_wall), data, cardinal[1]));
	else if (i == 3 && strcmp(cardinal[0], "EA") == 0)
		return (file_to_img(&(data->ea_wall), data, cardinal[1]));
	return (0);
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
		if (init_walls(data, cardinal, i))
		{
			free_split(cardinal);
			ft_errors(data, "Error initialising xpm to images", 1);
		}
		free_split(cardinal);
		i++;
	}
}
