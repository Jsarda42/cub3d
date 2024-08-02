/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:23:35 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/02 16:12:10 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// typedef struct s_player
// {
// }			t_player;

typedef struct s_map
{
	char	*filename;
	int		map_size;
	char	**map_str;
}			t_map;

// typedef struct s_mlx
// {
// }			t_mlx;

typedef struct s_prog
{
	t_map	map_data;
}			t_prog;

#endif
