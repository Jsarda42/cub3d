/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:39:18 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/19 15:15:45 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	mid_valid_char(t_prog *data, char c)
{
	if (c == '1')
		return ;
	if (c == '0')
		return ;
	if (c == ' ')
		return ;
	if (c == 'E' || c == 'N' || c == 'W' || c == 'S')
		return ;
	ft_errors(data, "Wrong character in mid line", -42);
}

void	ext_valid_char(t_prog *data, char c)
{
	if (c == ' ')
		return ;
	if (c == '1')
		return ;
	ft_errors(data, "Wrong character in extern line", -42);
}
