/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:48:47 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/08 16:33:01 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_first_line(t_prog *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\n')
			ft_errors(data, "Wrong map format in first line", -42);
		i++;
	}
	return ;
}

int	check_last_line(t_prog *data, char **map)
{
	static int	i = -1;
	int			y;

	y = 0;
	if (i == -1)
	{
		i = 0;
		while (map[i])
			i++;
		i--;
	}
	while (map[i][y])
	{
		if (map[i][y] != '1' && map[i][y] != ' ' && map[i][y] != '\n')
			ft_errors(data, "Wrong map format in last line", -42);
		if (map[i][y] == '1')
			return (i);
		y++;
	}
	if (i > 0)
	{
		i--;
		check_last_line(data, map);
	}
	return (i);
}

void	parse_map_grid(t_prog *data, int i)
{
	int	last;
	int mid;

	last = 0;
	mid = 0;
	check_first_line(data, data->map_data.map_str[i]);
	last = check_last_line(data, data->map_data.map_str);
	mid = last - 1;
	while (mid > i)
	{
		check_mid_line(data->map_data.map_str[mid]);
		mid--;
	}
}
