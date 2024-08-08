/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:23:54 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/08 13:52:35 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "structs.h"
# include <../mlx_linux/mlx_int.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>

// src
int		close_game(t_prog *data);


// init
void	init_data(t_prog *data, char **argv);
void	init_map(t_prog *data);
void	init_window(t_prog *data);

// parse
void	parse_map(t_prog *data);
int		parse_identifier(t_prog *data, char **map);
void	parse_map_grid(t_prog *data, int i);

// utils
void	del_data(t_prog *data);
int		ft_count_args(char **arg);
void	ft_errors(t_prog *data, char *message, int error_status);
void	free_all(t_prog *data);

#endif
