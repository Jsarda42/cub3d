/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:47:47 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/06 14:57:58 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	get_map_size(int fd, t_prog *data)
{
	char	*dummy;

	dummy = get_next_line(fd);
	data->map_data.map_size++;
	while (dummy)
	{
		free(dummy);
		dummy = get_next_line(fd);
		data->map_data.map_size++;
	}
	close(fd);
}

void	read_map(int fd, t_prog *data, char *map_name)
{
	int	i;

	i = 0;
	get_map_size(fd, data);
	data->map_data.map_str = ft_calloc(data->map_data.map_size + 1, sizeof(char **));
	if (!data->map_data.map_str)
		ft_errors(data, strerror(errno), errno);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_errors(data, "Error opening file", 1);
	data->map_data.map_str[i] = get_next_line(fd);
	while (data->map_data.map_str[i])
	{
		i++;
		data->map_data.map_str[i] = get_next_line(fd);
	}
}

void	init_map(t_prog *data)
{
	int		fd;
	char	*map_name;

	map_name = data->map_data.filename;
	if (ft_strlen(map_name) <= 4 || !ft_strnstr(map_name + (ft_strlen(map_name) - 4), ".cub", 5))
		ft_errors(data, "File format must be 'exemple.cub' or file does not exist", 1);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_errors(data, "Error opening file", 1);
	read_map(fd, data, map_name);
}
