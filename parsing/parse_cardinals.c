/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cardinals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:47:15 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 14:46:11 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	validate_cardinal_format(t_prog *data, char **cardinal)
{
	int	i;

	i = 0;
	while (cardinal[0][i] == ' ')
		i++;
	if ((cardinal[0][i] == 'N' && cardinal[0][i + 1] == 'O')
		|| (cardinal[0][i] == 'W' && cardinal[0][i + 1] == 'E')
		|| (cardinal[0][i] == 'S' && cardinal[0][i + 1] == 'O')
		|| (cardinal[0][i] == 'E' && cardinal[0][i + 1] == 'A'))
	{
		if (cardinal[0][i + 2] != '\0' && cardinal[0][i + 2] != ' ')
		{
			free_split(cardinal);
			ft_errors(data, "Wrong cardinal format", 1);
		}
	}
	else
	{
		free_split(cardinal);
		ft_errors(data, "Wrong cardinal", 1);
	}
}

void	assign_cardinal_texture(t_prog *data, char **cardinal)
{
	int	i;

	i = 0;
	while (cardinal[0][i] == ' ')
		i++;
	if (cardinal[0][i] == 'N' && cardinal[0][i + 1] == 'O'
		&& !data->no_wall.filename)
		data->no_wall.filename = ft_strdup(cardinal[1]);
	else if (cardinal[0][i] == 'W' && cardinal[0][i + 1] == 'E'
		&& !data->we_wall.filename)
		data->we_wall.filename = ft_strdup(cardinal[1]);
	else if (cardinal[0][i] == 'S' && cardinal[0][i + 1] == 'O'
		&& !data->so_wall.filename)
		data->so_wall.filename = ft_strdup(cardinal[1]);
	else if (cardinal[0][i] == 'E' && cardinal[0][i + 1] == 'A'
		&& !data->ea_wall.filename)
		data->ea_wall.filename = ft_strdup(cardinal[1]);
}

void	parse_cardinals(t_prog *data, char *cardinal_line)
{
	char	**cardinal;

	cardinal = ft_split(cardinal_line, ' ');
	if (ft_count_args(cardinal) != 2)
	{
		free_split(cardinal);
		ft_errors(data, "Cardinal : wrong number of arguments", 1);
	}
	validate_cardinal_format(data, cardinal);
	assign_cardinal_texture(data, cardinal);
	free_split(cardinal);
}
