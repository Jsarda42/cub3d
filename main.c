/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:11:34 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/06 15:19:43 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int	main(int argc, char **argv)
{
	t_prog	data;

	if (argc != 2)
		return (write(2, "Wrong number of arguments\n", 27), 194);
	init_data(&data, argv);
	init_map(&data);
	init_window(&data);
	init_texture(&data);
	mlx_hook(data.win_ptr, DestroyNotify, ButtonPressMask, &close_game, &data);
	mlx_loop(data.mlx_ptr);
	free_all(&data);
	return (0);
}
