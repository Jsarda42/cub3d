/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:47:15 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/14 11:52:19 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	extract_color(char *color_str)
{
	int	i;

	i = 0;
	color_str[ft_strlen(color_str) - 1] = '\0';
	while (color_str[i] == ' ')
		i++;
	return (ft_atoi(&color_str[i]));
}

int	parse_rgb_value(char *colors_line, int *i)
{
	int	value;

	value = 0;
	while (colors_line[*i] == ' ')
		(*i)++;
	if (!ft_isdigit(colors_line[*i]))
		return (-1);
	while (ft_isdigit(colors_line[*i]))
	{
		value = value * 10 + (colors_line[*i] - '0');
		if (value > 255)
			return (-1);
		(*i)++;
	}
	while (colors_line[*i] == ' ')
		(*i)++;
	return (value);
}

int	valid_rgb(char *colors_line, int *i)
{
	int	count;
	int	comma_count;
	int	value;

	count = 0;
	comma_count = -1;
	while (colors_line[*i])
	{
		value = parse_rgb_value(colors_line, i);
		if (value == -1)
			return (0);
		count++;
		if (comma_count++ != -2 && count < 3)
		{
			if (colors_line[(*i)++] != ',')
				return (0);
		}
		else if (count == 3)
		{
			if (colors_line[*i] == ',')
				return (0);
			break ;
		}
	}
	return (count == 3 && comma_count == 2);
}

void	check_line_args(t_prog *data, char *colors_line)
{
	int	i;
	int	checker;

	checker = 0;
	i = 0;
	while (colors_line[i])
	{
		while (colors_line[i] == ' ')
			i++;
		if (colors_line[i] == 'C' || colors_line[i] == 'F')
		{
			if (colors_line[i + 1] != ' ')
				ft_errors(data, "Identifier can only be C or F", -42);
			checker = checker + 1;
			if (checker > 1)
				ft_errors(data, "Too many identifiers in color line", -42);
			i++;
		}
		if (!valid_rgb(colors_line, &i))
			ft_errors(data, "Invalid RGB format", -42);
		while (colors_line[i] == ' ')
			i++;
		if (colors_line[i] != '\0')
			ft_errors(data, "Invalid characters after RGB values", -42);
	}
}

void	parse_colors(t_prog *data, char *colors_line)
{
	char	**colors;
	int		left_color;
	int		mid_color;
	int		right_color;

	left_color = 0;
	mid_color = 0;
	right_color = 0;
	check_line_args(data, colors_line);
	colors = ft_split(colors_line, ',');
	if (!colors)
		ft_errors(data, "Failed to split the colors", 1);
	left_color = extract_color(colors[0]);
	mid_color = extract_color(colors[1]);
	right_color = extract_color(colors[2]);
	if (in_range(left_color) && in_range(right_color) && in_range(mid_color))
	{
		free_split(colors);
		ft_errors(data, "Colors: value out of range (0-255)", 1);
	}
	free_split(colors);
}
