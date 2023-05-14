/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:24:36 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/14 18:04:50 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_player(t_map *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_ptr_p, map->pos_player_y
		*(map->height), map->pos_player_x *(map->width));
}

void	add_earth(t_map *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_pla,
		map->y * (map->height), map->x *(map->width));
}

void	add_exit(t_map *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_exit,
		map->y *(map->height), map->x *(map->width));
}

void	add_wall(t_map *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_ptr_w, map->y *(map->height), map->x *(map->width));
}

void	add_collectable(t_map *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_col,
		map->y *(map->height), map->x *(map->width));
}
