/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:20:13 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/06 15:21:31 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	close_game(t_prog *data)
{
	free_all(data);
	exit(0);
}

void	del_data(t_prog *data)
{
	if (!data)
		return ;
	free_split(data->map_data.map_str);
}