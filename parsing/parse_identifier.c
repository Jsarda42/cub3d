/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:47:15 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/08 13:58:51 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	define_wrong_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E'
			&& line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	define_first_line(char *line)
{
	int	has_seen_one;
	int	i;

	i = 0;
	has_seen_one = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == '1')
		{
			has_seen_one = 1;
			i++;
		}
		else
			break ;
	}
	return (has_seen_one);
}

void	check_number_of_identifier(t_prog *data, int *identifier)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (identifier[i++] != 1)
			ft_errors(data, "Wrong identifier or duplicate/not enough", 2);
	}
}

int	is_identifier(char identifier)
{
	if (identifier == 'N' || identifier == 'S' || identifier == 'W'
		|| identifier == 'E' || identifier == 'C' || identifier == 'F')
		return (1);
	return (0);
}

int	parse_identifier(t_prog *data, char **map)
{
	int	i;
	int j;
	int	identifier[6] = {0};

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (define_first_line(map[i]) != 0)
			break ;
		else if (map[i][j] == 'C')
		{
			parse_colors(data, map[i]);
			identifier[0]++;
		}
		else if (map[i][j] == 'F')
		{
			parse_colors(data, map[i]);
			identifier[1]++;
		}
		else if (map[i][j] == 'N')
		{
			parse_cardinals(data, map[i]);
			identifier[2]++;
		}
		else if (map[i][j] == 'S')
		{
			parse_cardinals(data, map[i]);
			identifier[3]++;
		}
		else if (map[i][j] == 'E')
		{
			parse_cardinals(data, map[i]);
			identifier[4]++;
		}
		else if (map[i][j] == 'W')
		{
			parse_cardinals(data, map[i]);
			identifier[5]++;
		}
		else if (define_wrong_line(map[i]))
			ft_errors(data, "Wrong identifier", 2);
	}
	check_number_of_identifier(data, identifier);
	return (i);
}
