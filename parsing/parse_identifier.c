/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:47:15 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 14:50:26 by jsarda           ###   ########.fr       */
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
		if (line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E')
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

int	process_line(char *line, int start, t_prog *data, int *identifier)
{
	char	type;

	type = line[start];
	if (type == 'C' || type == 'F')
	{
		parse_colors(data, line);
		if (type == 'C')
			return (identifier[0]++, 1);
		else
			return (identifier[1]++, 1);
	}
	else if (type == 'N' || type == 'S' || type == 'E' || type == 'W')
	{
		parse_cardinals(data, line);
		if (type == 'N')
			identifier[2]++;
		else if (type == 'S')
			identifier[3]++;
		else if (type == 'E')
			identifier[4]++;
		else
			identifier[5]++;
		return (1);
	}
	return (0);
}

int	parse_identifier(t_prog *data, char **map)
{
	int			i;
	int			j;
	static int	identifier[6] = {0};

	i = 0;
	while (map[i])
	{
		j = 0;
		if (define_first_line(map[i]) != 0)
			break ;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] && !process_line(map[i], j, data, identifier))
			ft_errors(data, "Wrong identifier", 2);
		i++;
	}
	check_number_of_identifier(data, identifier);
	return (i);
}
