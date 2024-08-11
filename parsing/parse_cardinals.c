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

void	parse_cardinals(t_prog *data, char *cardinal_line)
{
    char **cardinal;
    int i;

    i = 0;
    cardinal = ft_split(cardinal_line, ' ');
	if (ft_count_args(cardinal) != 2)
	{
		free_split(cardinal);
		ft_errors(data, "Cardinal : wrong number of arguments", 1);
	}
    while (cardinal[0][i] == ' ')
        i++;
    if (cardinal[0][i] == 'N' && cardinal[0][i + 1] != 'O')
    {
        free_split(cardinal);
        ft_errors(data, "Wrong cardinal", 1);
    }
    else
        data->no_wall.filename = ft_strdup(cardinal[1]);
    if (cardinal[0][i] == 'W' && cardinal[0][i + 1] != 'E')
    {
        free_split(cardinal);
        ft_errors(data, "Wrong cardinal", 1);
    }
    else
        data->we_wall.filename = ft_strdup(cardinal[1]);
    if (cardinal[0][i] == 'S' && cardinal[0][i + 1] != 'O')
    {
        free_split(cardinal);
        ft_errors(data, "Wrong cardinal", 1);
    }
    else
        data->so_wall.filename = ft_strdup(cardinal[1]);
    if (cardinal[0][i] == 'E' && cardinal[0][i + 1] != 'A')
    {
        free_split(cardinal);
        ft_errors(data, "Wrong cardinal", 1);
    }
    else
        data->ea_wall.filename = ft_strdup(cardinal[1]);
    free_split(cardinal);
}
