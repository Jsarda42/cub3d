/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:23:35 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 14:26:38 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_image
{
	char *filename;
	void *xpm_ptr;
	int h;
	int w;
} t_image;

typedef struct s_map
{
	char *filename;
	int map_size;
	char **map_str;
	char **game_map;
} t_map;

typedef struct s_line
{
	int x;
	int y;
} t_line;

typedef struct s_player // the player structure
{
	int plyr_x;	  // player x position in pixels
	int plyr_y;	  // player y position in pixels
	int player_x; // on map
	int player_y; // on map
	double angle; // player angle
	float fov_rd; // field of view in radians
	int rot;	  // rotation flag
	int l_r;	  // left right flag
	int u_d;	  // up down flag
} t_player;

typedef struct s_prog
{
	int s_h;
	int s_w;
	t_map map_data;
	t_line line;
	t_image no_wall;
	t_image so_wall;
	t_image we_wall;
	t_image ea_wall;
	t_player player;
	void *mlx_ptr;
	void *win_ptr;
} t_prog;

#endif
