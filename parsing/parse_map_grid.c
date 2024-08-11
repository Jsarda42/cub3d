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

int	check_last_line(t_prog *data, char **map, int last, int first)
{
	int	y;

	last--;
	while (last > first)
	{
		y = 0;
		while (map[last][y])
		{
			if (map[last][y] != ' ' && map[last][y] != '1' && map[last][y] != '\n')
				ft_errors(data, "Wrong map format in last line", -42);
			if (map[last][y] == '1')
			{
				y = 0;
				while (map[last][y])
				{
					if (map[last][y] != ' ' && map[last][y] != '1' && map[last][y] != '\n')
						ft_errors(data, "Wrong map format in last line", -42);
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


void	is_valid_char(t_prog *data, char c)
{
	if (c == '1')
		return ;
	if (c == '0')
		return ;
	if (c == ' ')
		return ;
	if (c == '\n')
		return ;
	if (c == 'E' || c == 'N' || c == 'W' || c == 'S')
		return ;
	ft_errors(data, "Wrong character in mid line", -42);
}

int is_player_position(char c)
{
	if (c == 'E' || c == 'N' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

void	check_mid_line(t_prog *data, char **map, int row)
{
	int	col;

	col = 0;
	while (map[row][col])
	{
		is_valid_char(data, map[row][col]);
		if (map[row][col] == '0' || is_player_position(map[row][col]))
		{
			if (row == 0 || !map[row - 1][col] || map[row - 1][col] == ' ')
				ft_errors(data, "Map has a hole (missing top wall)", -42);
			if (!map[row + 1] || map[row + 1][col] == ' ' || map[row + 1][col] == '\0')
				ft_errors(data, "Map has a hole (missing bottom wall)", -42);
			if (col == 0 || map[row][col - 1] == ' ')
				ft_errors(data, "Map has a hole (missing left wall)", -42);
			if (!map[row][col + 1] || map[row][col + 1] == ' ' || map[row][col + 1] == '\0')
				ft_errors(data, "Map has a hole (missing right wall)", -42);
		}
		col++;
	}
}

void	parse_map_grid(t_prog *data, int i)
{
	int	last;
	int mid;

	last = 0;
	mid = 0;
	check_first_line(data, data->map_data.map_str[i]);
	last = i;
	while (data->map_data.map_str[last])
		last++;
	last = check_last_line(data, data->map_data.map_str, last, i);
	mid = last - 1;
	while (mid > i)
	{
		check_mid_line(data, data->map_data.map_str, mid);
		mid--;
	}
}
