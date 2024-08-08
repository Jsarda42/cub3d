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

static int	file_to_img(t_image *image, t_prog *data, char *filename)
{
	image->xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, filename, &(image->w),
			&(image->h));
	if (!image->xpm_ptr)
		return (1);
	return (0);
}

static int	init_walls(t_prog *data, char **cardinal)
{
	cardinal[1][ft_strlen(cardinal[1]) - 1] = '\0';
	if (strcmp(cardinal[0], " ") == 0)
		return (0);
	if (!data->no_wall.xpm_ptr && strcmp(cardinal[0], "NO") == 0)
		return (file_to_img(&(data->no_wall), data, cardinal[1]));
	else if (!data->so_wall.xpm_ptr && strcmp(cardinal[0], "SO") == 0)
		return (file_to_img(&(data->so_wall), data, cardinal[1]));
	else if (!data->we_wall.xpm_ptr && strcmp(cardinal[0], "WE") == 0)
		return (file_to_img(&(data->we_wall), data, cardinal[1]));
	else if (!data->ea_wall.xpm_ptr && strcmp(cardinal[0], "EA") == 0)
		return (file_to_img(&(data->ea_wall), data, cardinal[1]));
	return (0);
}

int	is_cardinal(char identifier)
{
	if (identifier == 'N' || identifier == 'S' || identifier == 'W'
		|| identifier == 'E')
		return (1);
	return (0);
}

int	is_colors(char identifier)
{
	if (identifier == 'F' || identifier == 'C')
		return (1);
	return (0);
}

void	parse_cardinal(t_prog *data, char **identifier)
{
	if (ft_count_args(identifier) != 2)
	{
		free_split(identifier);
		ft_errors(data, "Cardinal : wrong number of arguments", 1);
	}
	if (init_walls(data, identifier))
	{
		free_split(identifier);
		ft_errors(data, "Error initialising xpm to images", 1);
	}
}

void	parse_colors(t_prog *data, char **identifier)
{
	if (ft_count_args(identifier) != 4)
	{
		free_split(identifier);
		ft_errors(data, "Colors : wrong number of arguments", 1);
	}
}

// int	parse_identifier(t_prog *data, int i)
// {
// 	char	**identifier;
// 	int		checker;

// 	checker = 0;
// 	identifier = ft_split(data->map_data.map_str[i], ' ');
// 	if (is_cardinal(identifier[0][0]))
// 	{
// 		checker = 1;
// 		parse_cardinal(data, identifier);
// 	}
// 	else if (is_colors(identifier[0][0]))
// 	{
// 		checker = 1;
// 		parse_colors(data, identifier);
// 	}
// 	if (!is_cardinal(identifier[0][0]) && !is_colors(identifier[0][0])
// 		&& identifier[0][0] != ' ' && identifier[0][0] != '\n')
// 	{
// 		free_split(identifier);
// 		ft_errors(data, "Not enough or wrong identifier", -42);
// 	}
// 	free_split(identifier);
// 	return (checker);
// }

