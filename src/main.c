/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:11:34 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 13:01:17 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_prog	data;

	if (argc != 2)
		return (write(2, "Wrong number of arguments\n", 27), 194);
	init_data(&data, argv);
	init_map(&data);
	parse_map(&data);
	init_the_player(&data);
	init_textures(&data);
	init_window(&data);
	mlx_hook(data.win_ptr, DestroyNotify, ButtonPressMask, &close_game, &data);
	mlx_loop(data.mlx_ptr);
	free_all(&data);
	return (0);
}
