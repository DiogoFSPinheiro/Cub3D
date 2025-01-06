/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:46:02 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/13 16:46:02 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	first_check(t_temp_map *map, int i)
{
	while (map->lines[i] != NULL)
	{
		ft_invalid_start(map, map->lines[i][0], i);
		i++;
	}
}

int	check_line_player(int start, char c, t_temp_map *map)
{
	if (start != 0 && c != '\0' && c != '\n'
		&& c != 'N' && c != 'S'
		&& c != 'E' && c != 'W'
		&& c != '1' && c != '0'
		&& c != ' ')
		error_central(-7, map);
	return (0);
}
