/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:27:50 by jsarda            #+#    #+#             */
/*   Updated: 2024/08/08 14:28:17 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_errors(t_prog *data, char *message, int error_status)
{
	free_all(data);
	printf("%s\n", message);
	exit(error_status);
}
