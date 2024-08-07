/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:23:35 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/06 16:11:20 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_image
{
	void	*xpm_ptr;
	int		h;
	int		w;
}			t_image;

typedef struct s_map
{
	char	*filename;
	int		map_size;
	char	**map_str;
}			t_map;

typedef struct s_line
{
	int x;
	int y;
} t_line;

typedef struct s_prog
{
	t_map	map_data;
	t_line line;
	t_image	no_wall;
	t_image	so_wall;
	t_image	we_wall;
	t_image	ea_wall;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_prog;

#endif
