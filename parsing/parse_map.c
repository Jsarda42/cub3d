/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:30:19 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/02 20:05:19 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_cardinal(char *cardinal, int i)
{
	if (i == 0 && strcmp(cardinal, "NO") == 0)
	{
		printf("initialised\n");
		// init_image(cardinal_p[1]);
	}
	else if (i == 1 && strcmp(cardinal, "SO") == 0)
	{
		printf("initialised\n");
		// init_image(cardinal_p[1]);
	}
	else if (i == 2 && strcmp(cardinal, "WE") == 0)
	{
		printf("initialised\n");
		// init_image(cardinal_p[1]);
	}
	else if (i == 3 && strcmp(cardinal, "EA") == 0)
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
		if (ft_count_args(cardinal) != 2)
			return (ft_errors("Wrong cardinal identifier", -42));
		check_cardinal(cardinal[0], i);
		free_split(cardinal);
		cardinal = NULL;
		i++;
	}
}
