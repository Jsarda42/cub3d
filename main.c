/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:11:34 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/02 16:08:18 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int	main(int argc, char **argv)
{
	t_prog	data;

	if (argc != 2)
		ft_errors("Wrong number of arguments", 450);
	init_data(&data, argv);
	init_map(&data);
	init_texture(&data);
	free_split(data.map_data.map_str);
}
