/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:33:15 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/19 07:33:15 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_get_max_line(int i, t_temp_map *map)
{
	int	max_len;

	max_len = -1;
	while (map->lines[i] != NULL)
	{
		if ((int)ft_strlen(map->lines[i]) > max_len)
			max_len = (int)ft_strlen(map->lines[i]);
		i++;
	}
	return (max_len + 1);
}

int	ft_get_colors(t_temp_map *map, int c)
{
	int		i;
	int		hex_color;
	char	**temp;
	char	*color;

	i = 0;
	hex_color = 0;
	temp = NULL;
	while (map->lines[i] && map->lines[i][0] != c)
		i++;
	if (map->lines[i] && map->lines[i][0] == c)
	{
		temp = ft_split(map->lines[i], ' ');
		color = ft_strdup(temp[1]);
		free_split(temp);
		temp = ft_split(color, ',');
		hex_color = rgb_to_int(ft_atoi(temp[0]),
				ft_atoi(temp[1]), ft_atoi(temp[2]));
		free_split(temp);
		free(color);
	}
	return (hex_color);
}

char	**get_final_map(t_temp_map *map)
{
	int		i;
	int		j;
	char	**new_map;
	int		max_line;

	i = 0;
	j = 0;
	new_map = NULL;
	first_check(map, 0, 0);
	while (map->lines && map->lines[i][j] != '0'
			&& map->lines[i][j] != '1' && map->lines[i][j] != ' ')
		i++;
	new_map = ft_calloc(sizeof(char *), (map->size - i) + 1);
	max_line = ft_get_max_line(i, map);
	while (map->lines[i] != NULL)
	{
		new_map[j] = ft_copy_line(map->lines[i], max_line);
		i++;
		j++;
	}
	new_map[j] = NULL;
	return (new_map);
}

int	get_map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char	*get_texture_path(t_temp_map *map, int c)
{
	int		i;
	char	**temp;
	char	*path;

	path = NULL;
	i = 0;
	while (map->lines[i] && map->lines[i][0] != c)
		i++;
	if (map->lines[i][0] == c)
	{
		temp = ft_split(map->lines[i], ' ');
		path = ft_strdup(temp[1]);
		free_split(temp);
	}
	return (path);
}