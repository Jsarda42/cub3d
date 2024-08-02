/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:27:12 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/02 13:56:50 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_data(t_prog *data, char **argv)
{
	data->map_data.filename = argv[1];
	data->map_data.map_str = NULL;
	data->map_data.map_size = 0;
}
