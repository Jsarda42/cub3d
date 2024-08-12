/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:37:23 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/12 13:18:57 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_count_args(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

void	check_args_nbr(t_prog *data, char **str, int nbr)
{
	if (ft_count_args(str) != nbr)
	{
		free_split(str);
		ft_errors(data, "Cardinal : wrong number of arguments", 1);
	}
}

int	is_identifier(char identifier)
{
	if (identifier == 'N' || identifier == 'S' || identifier == 'W'
		|| identifier == 'E' || identifier == 'C' || identifier == 'F')
		return (1);
	return (0);
}
