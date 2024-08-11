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

int extract_color(char *color_str)
{
    int i = 0;

    while (color_str[i] == ' ')
        i++;
    return (ft_atoi(&color_str[i]));
}

void	parse_colors(t_prog *data, char *colors_line)
{
    char **colors;
    int left_color = 0;
    int mid_color = 0;
    int right_color = 0;

    if (colors_line[0] == 'F' || colors_line[0] == 'C')
    {
        if (colors_line[1] != ' ')
            ft_errors(data, "Wrong color identifier", 1);
        colors_line += 2;
    }

    colors = ft_split(colors_line, ',');
    if (ft_count_args(colors) != 3)
    {
        free_split(colors);
        ft_errors(data, "Colors: wrong number of arguments", 1);
    }

    left_color = extract_color(colors[0]);
    mid_color = extract_color(colors[1]);
    right_color = extract_color(colors[2]);

    if (left_color < 0 || left_color > 255 ||
        mid_color < 0 || mid_color > 255 ||
        right_color < 0 || right_color > 255)
    {
        free_split(colors);
        ft_errors(data, "Colors: value out of range (0-255)", 1);
    }
    free_split(colors);
}
