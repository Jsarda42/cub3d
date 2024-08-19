/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:48:47 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 13:05:29 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_first_line(t_prog *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
			ft_errors(data, "Wrong map format in first line", -42);
		i++;
	}
	return ;
}

int	check_last_line(t_prog *data, char **map, int last, int first)
{
	int	y;

	last--;
	while (last > first)
	{
		y = 0;
		while (map[last][y])
		{
			ext_valid_char(data, map[last][y]);
			if (map[last][y] == '1')
			{
				y = 0;
				while (map[last][y])
				{
					ext_valid_char(data, map[last][y]);
					y++;
				}
				return (last);
			}
			y++;
		}
		last--;
	}
	return (last);
}

int	is_player_position(char c)
{
	if (c == 'E' || c == 'N' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

int	check_mid_line(t_prog *data, char **map, int row)
{
	int	col;
	int	player_number;

	player_number = 0;
	col = -1;

	while (map[row][++col])
	{
		if (is_player_position(map[row][col]))
		{
			player_number += 1;
			data->player.player_x = col;
			data->player.player_y = row;
		}
		mid_valid_char(data, map[row][col]);
		if (map[row][col] == '0' || is_player_position(map[row][col]))
		{
			if (row == 0 || !map[row - 1][col] || map[row - 1][col] == ' ')
				ft_errors(data, "Wrong map format", -42);
			if (!map[row + 1] || map[row + 1][col] == ' ' || map[row
				+ 1][col] == '\0')
				ft_errors(data, "Wrong map format", -42);
			if (col == 0 || map[row][col - 1] == ' ')
				ft_errors(data, "Wrong map format", -42);
			if (!map[row][col + 1] || map[row][col + 1] == ' ' || map[row][col
				+ 1] == '\0')
				ft_errors(data, "Wrong map format", -42);
		}
	}
	return (player_number);
}

void	parse_map_grid(t_prog *data, int i)
{
	int	last;
	int	mid;
	int	player_number;

	player_number = 0;
	last = 0;
	mid = 0;
	printf("i = %d\n", i);
	check_first_line(data, data->map_data.map_str[i]);
	last = i;
	while (data->map_data.map_str[last])
		last++;
	last = check_last_line(data, data->map_data.map_str, last, i);
	mid = last;
	while (mid > i)
	{
		player_number += check_mid_line(data, data->map_data.map_str, mid);
		if (player_number > 1)
			ft_errors(data, "Too many players", -42);
		mid--;
	}
	if (player_number == 0)
		ft_errors(data, "1 player needed", -42);
}
