/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:15:57 by ftanon            #+#    #+#             */
/*   Updated: 2024/08/19 15:17:22 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_the_player(t_prog *data)
{
	printf("x = %d\n", data->player.player_x);
	printf("y = %d\n", data->player.player_y);
	data->player.plyr_x = data->player.player_x * TILE_SIZE + TILE_SIZE / 2;
		// player x position in pixels in the center of the tile
	data->player.plyr_y = data->player.player_y * TILE_SIZE + TILE_SIZE / 2;
		// player y position in pixels in the center of the tile
	data->player.fov_rd = (FOV * M_PI) / 180;
		// field of view in radians
	data->player.angle = M_PI;
		// player angle
	// the rest of the variables are initialized to zero by calloc
	printf("x = %d\n", data->player.plyr_x);
	printf("y = %d\n", data->player.plyr_y);
	printf("fov = %f\n", data->player.fov_rd);
	printf("angle = %f\n", data->player.angle);
}
