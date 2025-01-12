/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:23:18 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/02 15:52:54 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	free_textures_map(t_mlx *mlx)
{
	free(mlx->west_texture.path);
	free(mlx->east_texture.path);
	free(mlx->south_texture.path);
	free(mlx->north_texture.path);
	if (mlx->map != NULL)
	{
		free_split(mlx->map->coord);
		free(mlx->map);
	}
}

void	ft_cleanup_and_exit(t_mlx *mlx)
{
	if (mlx->mlx_connect != NULL)
	{
		mlx_destroy_image(mlx->mlx_connect, mlx->img.mlx_img);
		if (mlx->north_texture.mlx_img)
			mlx_destroy_image(mlx->mlx_connect, mlx->north_texture.mlx_img);
		if (mlx->south_texture.mlx_img)
			mlx_destroy_image(mlx->mlx_connect, mlx->south_texture.mlx_img);
		if (mlx->east_texture.mlx_img)
			mlx_destroy_image(mlx->mlx_connect, mlx->east_texture.mlx_img);
		if (mlx->west_texture.mlx_img)
			mlx_destroy_image(mlx->mlx_connect, mlx->west_texture.mlx_img);
		if (mlx->mlx_win != NULL)
			mlx_destroy_window(mlx->mlx_connect, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_connect);
		free(mlx->mlx_connect);
	}
	free_textures_map(mlx);
	if (mlx->player != NULL)
		free(mlx->player);
	free(mlx);
	exit(0);
}

int	ft_close(t_mlx *mlx)
{
	ft_cleanup_and_exit(mlx);
	return (0);
}

int	ft_event_checker(int Key, t_mlx *mlx)
{
	if (Key == XK_Escape)
		ft_cleanup_and_exit(mlx);
	return (0);
}
