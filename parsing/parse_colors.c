/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:47:15 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/12 11:19:03 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	extract_color(char *color_str)
{
	int	i;

	i = 0;
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

void	parse_colors(t_prog *data, char *colors_line)
{
	char	**colors;
	int		left_color;
	int		mid_color;
	int		right_color;

	left_color = 0;
	mid_color = 0;
	right_color = 0;
	if (colors_line[0] == 'F' || colors_line[0] == 'C')
	{
		if (colors_line[1] != ' ')
			ft_errors(data, "Wrong color identifier", 1);
		colors_line += 2;
	}
	colors = ft_split(colors_line, ',');
	check_args_nbr(data, colors, 3);
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
