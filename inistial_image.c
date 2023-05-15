/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inistial_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:07:13 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/15 12:16:21 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insial_colectebal(t_map *map)
{
	if (map->img_ptr_col != NULL)
		mlx_destroy_image(map->mlx_ptr, map->img_ptr_col);
	map->img_ptr_col = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/treasure.xpm", &(map->width), &(map->height));
	if (map->img_ptr_col == NULL)
		ft_error("Error\n");
}

void	insial_earth(t_map *map)
{
	if (map->img_ptr_pla != NULL)
		mlx_destroy_image(map->mlx_ptr, map->img_ptr_pla);
	map->img_ptr_pla = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/sur.xpm", &(map->width), &(map->height));
	if (map->img_ptr_pla == NULL)
		ft_error("Error\n");
}

void	insial_exit(t_map *map)
{
	if (map->img_ptr_exit != NULL)
		mlx_destroy_image(map->mlx_ptr, map->img_ptr_exit);
	map->img_ptr_exit = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/black-hol.xpm", &(map->width), &(map->height));
	if (map->img_ptr_exit == NULL)
		ft_error("Error\n");
}

void	insial_player(t_map *map)
{
	if (map->img_ptr_p != NULL)
		mlx_destroy_image(map->mlx_ptr, map->img_ptr_p);
	if (map->imp_pos == 1)
		map->img_ptr_p = mlx_xpm_file_to_image(map->mlx_ptr,
				"textures/super_mario.xpm", &(map->width), &(map->height));
	else if (map->imp_pos == 0)
		map->img_ptr_p = mlx_xpm_file_to_image(map->mlx_ptr,
				"textures/super_mario.xpm", &(map->width), &(map->height));
	else if (map->imp_pos == 2)
		map->img_ptr_p = mlx_xpm_file_to_image(map->mlx_ptr,
				"textures/left_mario.xpm", &(map->width), &(map->height));
	else if (map->imp_pos == 3)
		map->img_ptr_p = mlx_xpm_file_to_image(map->mlx_ptr,
				"textures/right_mario.xpm", &(map->width), &(map->height));
	if (map->img_ptr_p == NULL)
		ft_error("Error\n");
	map->imp_pos = 0;
}

void	insial_wall(t_map *map)
{
	if (map->img_ptr_w != NULL)
		mlx_destroy_image(map->mlx_ptr, map->img_ptr_w);
	map->img_ptr_w = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/wal.xpm", &(map->width), &(map->height));
	if (map->img_ptr_w == NULL)
		ft_error("Error\n");
}
