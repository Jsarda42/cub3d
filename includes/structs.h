/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:23:35 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/02 21:09:54 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// typedef struct s_player
// {
// }			t_player;

typedef struct s_image
{
	void	*xpm_ptr;
	char	*xpm_file;
	int		h;
	int		w;
} t_image;

typedef struct s_sprite
{
	t_image wall;
	t_image player;
} t_sprite;

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
	t_sprite	sprite;
	void	*mlx_ptr;
}			t_prog;

#endif
