/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:23:54 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 12:34:46 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include "structs.h"
#include <../mlx_linux/mlx_int.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define TILE_SIZE 30
#define FOV 60
#define M_PI 3.14159265358979323846

// src
int close_game(t_prog *data);

// init
void init_data(t_prog *data, char **argv);
void init_map(t_prog *data);
void init_window(t_prog *data);
void init_textures(t_prog *data);
void init_the_player(t_prog *data);

// parse
void parse_map(t_prog *data);
int parse_identifier(t_prog *data, char **map);
void parse_map_grid(t_prog *data, int i);
void parse_cardinals(t_prog *data, char *cardinal_line);
void parse_colors(t_prog *data, char *colors_line);

// utils
void del_data(t_prog *data);
int ft_count_args(char **arg);
void ft_errors(t_prog *data, char *message, int error_status);
void free_all(t_prog *data);
void check_args_nbr(t_prog *data, char **str, int nbr);
void mid_valid_char(t_prog *data, char c);
void ext_valid_char(t_prog *data, char c);
int is_identifier(char identifier);
int in_range(int color);

#endif
