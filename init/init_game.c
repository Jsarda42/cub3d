/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:27:12 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 14:26:59 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void init_player(t_prog *data)
{
	data->player.player_x = 0;
	data->player.player_y = 0;
}

void init_walls(t_prog *data)
{
	data->ea_wall.h = 300;
	data->no_wall.h = 300;
	data->we_wall.h = 300;
	data->so_wall.h = 300;
	data->ea_wall.w = 300;
	data->no_wall.w = 300;
	data->we_wall.w = 300;
	data->so_wall.w = 300;
	data->no_wall.xpm_ptr = NULL;
	data->so_wall.xpm_ptr = NULL;
	data->we_wall.xpm_ptr = NULL;
	data->ea_wall.xpm_ptr = NULL;
	data->no_wall.filename = NULL;
	data->ea_wall.filename = NULL;
	data->we_wall.filename = NULL;
	data->so_wall.filename = NULL;
}

void init_data(t_prog *data, char **argv)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_errors(data, "Error initialising mlx", -41);
	data->map_data.filename = argv[1];
	data->map_data.map_str = NULL;
	data->map_data.game_map = NULL;
	data->map_data.map_size = 0;
	data->win_ptr = NULL;
	data->s_h = 0;
	data->s_w = 0;
	init_walls(data);
	init_player(data);
}
