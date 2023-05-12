/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:24:36 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/12 17:46:27 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_player(t_map *map)
{
	if (map->img_ptr_p != NULL)
		mlx_destroy_image(map->mlx_ptr, map->img_ptr_p);
	if (map->imp_pos == 1)
		map->img_ptr_p = mlx_xpm_file_to_image(map->mlx_ptr,
				"super_mario.xpm", &(map->width), &(map->height));
	else if (map->imp_pos == 0)
		map->img_ptr_p = mlx_xpm_file_to_image(map->mlx_ptr,
				"super_mario.xpm", &(map->width), &(map->height));
	else if (map->imp_pos == 2)
		map->img_ptr_p = mlx_xpm_file_to_image(map->mlx_ptr,
				"left_mario.xpm", &(map->width), &(map->height));
	else if (map->imp_pos == 3)
		map->img_ptr_p = mlx_xpm_file_to_image(map->mlx_ptr,
				"right_mario.xpm", &(map->width), &(map->height));
	if (!(map->img_ptr_p))
		ft_error("Error\n");
	map->imp_pos = 0;
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_ptr_p, map->pos_player_y
		*(map->height), map->pos_player_x *(map->width));
}

void	add_earth(t_map *map)
{
	if (map->img_ptr_pla != NULL)
		mlx_destroy_image(map->mlx_ptr, map->img_ptr_pla);
	map->img_ptr_pla = mlx_xpm_file_to_image(map->mlx_ptr,
			"sur.xpm", &(map->width), &(map->height));
	if (!(map->img_ptr_pla))
		ft_error("Error\n");
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_pla,
		map->y * (map->height), map->x *(map->width));
}

void	add_exit(t_map *map)
{
	if (map->img_ptr_exit != NULL)
		mlx_destroy_image(map->mlx_ptr, map->img_ptr_exit);
	map->img_ptr_exit = mlx_xpm_file_to_image(map->mlx_ptr,
			"black-hol.xpm", &(map->width), &(map->height));
	if (!(map->img_ptr_exit))
		ft_error("Error\n");
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_exit,
		map->y *(map->height), map->x *(map->width));
}

void	add_wall(t_map *map)
{
	if (map->img_ptr_w != NULL)
		mlx_destroy_image(map->mlx_ptr, map->img_ptr_w);
	map->img_ptr_w = mlx_xpm_file_to_image(map->mlx_ptr,
			"wal.xpm", &(map->width), &(map->height));
	if (!(map->img_ptr_w))
		ft_error("Error\n");
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_ptr_w, map->y *(map->height), map->x *(map->width));
}

void	add_collectable(t_map *map)
{
	if (map->img_ptr_col != NULL)
		mlx_destroy_image(map->mlx_ptr, map->img_ptr_col);
	map->img_ptr_col = mlx_xpm_file_to_image(map->mlx_ptr,
			"treasure.xpm", &(map->width), &(map->height));
	if (!(map->img_ptr_col))
		ft_error("Error\n");
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_col,
		map->y *(map->height), map->x *(map->width));
}
