/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:00:15 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 13:19:27 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



void	parse_map(t_prog *data)
{
	char	**map;
	int		i;

	i = 0;
	map = data->map_data.map_str;
	i = parse_identifier(data, map);
	// // store game_map
	// char **game_map;
	// game_map = malloc(sizeof(char *) * ft_strlen(map + i));
	printf("%d\n", ft_strlen(map + i));
	parse_map_grid(data, i);
}
