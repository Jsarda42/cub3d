/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:30:19 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/02 16:32:39 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_cardinal(char **cardinal, int i)
{
	if (i == 0 && strcmp(cardinal[0], "NO"))
	{
		printf("initialised\n");
		// init_image(cardinal_p[1]);
	}
	else if (i == 1 && strcmp(cardinal[0], "SO"))
	{
		printf("initialised\n");
		// init_image(cardinal_p[1]);
	}
	else if (i == 2 && strcmp(cardinal[0], "We"))
	{
		printf("initialised\n");
		// init_image(cardinal_p[1]);
	}
	else if (i == 3 && strcmp(cardinal[0], "EA"))
	{
		printf("initialised\n");
		// init_image(cardinal_p[1]);
	}
}

void	init_texture(t_prog *data)
{
	char	**map;
	char	**cardinal;
	int		i;

	i = 0;
	cardinal = ft_calloc(6, sizeof(char **));
	map = data->map_data.map_str;
	while (i < 4)
	{
		cardinal = ft_split(map[i], ' ');
		printf("cardinal 0 = %s\n", cardinal[0]);
		printf("cardinal 1 = %s\n", cardinal[1]);
		if (ft_count_args(cardinal) != 2)
			return (ft_errors("Format should be 'Direction' ./texture_filename please check your map file",
					1));
		check_cardinal(cardinal, i);
		free_split(cardinal);
		cardinal = NULL;
		i++;
	}
}
