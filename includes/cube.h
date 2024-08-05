/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:23:54 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/02 16:13:03 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "structs.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>

void	init_data(t_prog *data, char **argv);
void	init_map(t_prog *data);
void	init_texture(t_prog *data);

int		ft_count_args(char **arg);

void	ft_errors(char *message, int error_status);

#endif