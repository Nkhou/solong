/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:15:51 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/15 15:11:14 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_puts(t_map *map)
{
	insial_earth(map);
	insial_player(map);
	insial_exit(map);
	insial_colectebal(map);
	insial_wall(map);
}

int	put_images(t_map *map)
{
	int	width;
	int	height;

	width = map->width * ft_strnline(map->map[0]);
	height = map->height * map->len;
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		ft_error("Error\n");
	ft_puts(map);
	map->win_ptr = mlx_new_window(map->mlx_ptr, width, height, "so_long");
	find_player(map->map, map->len, map);
	dispaly_imag(map);
	return (0);
}
