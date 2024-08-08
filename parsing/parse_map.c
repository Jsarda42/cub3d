/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:00:15 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/08 13:49:06 by jsarda           ###   ########.fr       */
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
	parse_map_grid(data, i);
}
