/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:47:15 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/14 09:57:51 by jsarda           ###   ########.fr       */
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

int	in_range(int color)
{
	if (color >= 0 && color <= 255)
		return (0);
	return (1);
}

int	valid_Rgb(char *colors_line, int *i)
{
	int	value;
	int	count;
	int	comma_count;

	count = 0;
	comma_count = 0;
	while (colors_line[*i])
	{
		while (colors_line[*i] == ' ')
			(*i)++;
		if (!ft_isdigit(colors_line[*i]))
			return (0);
		value = 0;
		while (ft_isdigit(colors_line[*i]))
		{
			value = value * 10 + (colors_line[*i] - '0');
			if (value > 255)
				return (0);
			(*i)++;
		}
		count++;
		while (colors_line[*i] == ' ')
			(*i)++;
		if (count < 3)
		{
			if (colors_line[*i] != ',')
				return (0);
			comma_count++;
			(*i)++;
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
		if (!valid_Rgb(colors_line, &i))
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
