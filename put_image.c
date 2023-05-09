/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:15:51 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/09 18:57:07 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int put_images(t_map *map)
{
	int width;
	int height;

	width = map->width * ft_strnline(map->map[0]);
	height = map->height * map->len;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, width, height, "so_long");
	find_player(map->map, map->len, map);
	dispaly_imag(map);
	return (0);
}