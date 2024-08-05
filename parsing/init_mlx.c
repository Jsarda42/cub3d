/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:10:25 by juliensarda       #+#    #+#             */
/*   Updated: 2024/08/02 21:16:31 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_images(t_sprite *sprite)
{
	sprite->player.h = 
	sprite->player.w =
	sprite->player.xpm_file = // xpm file for player
	sprite->player.xpm_ptr = NULL;
	sprite->wall.h =
	sprite->wall.w =
	sprite->wall.xpm_file = 
	sprite->wall.xpm_ptr = NULL;
}

// 	t_sprite sprite;

//sprite.wall.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, &sprite.wall.xpm_file, &sprite.wall.w, &sprite.wall.h);
//	sprite.player.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, &sprite.player.xpm_file, &sprite.wall.w, &sprite.wall.h);