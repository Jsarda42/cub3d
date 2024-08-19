/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:00:15 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 15:57:03 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	parse_map(t_prog *data)
{
	char	**map;
	int		i;
	int		j;
	int		game_map_len;


	game_map_len = 0;
	i = 0;
	j = 0;
	map = data->map_data.map_str;
	i = parse_identifier(data, map);
	game_map_len = data->map_data.map_size - i;
	data->map_data.game_map = malloc(sizeof(char *) * game_map_len);
	while (j < game_map_len)
	{
		data->map_data.game_map[j] = ft_strdup(map[i + j]);
		// printf("map str = %s\n", map[i + j]);
		// printf("map game map = %s\n", data->map_data.game_map[j]);

		j++;
	}
	parse_map_grid(data);
}
