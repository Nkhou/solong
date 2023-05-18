/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:16:47 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/17 20:13:43 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_map *my_map)
{
	if (my_map != NULL)
	{	
		frre_table(my_map->map);
		mlx_destroy_image(my_map->mlx_ptr, my_map->img_ptr_w);
		mlx_destroy_image(my_map->mlx_ptr, my_map->img_ptr_col);
		mlx_destroy_image(my_map->mlx_ptr, my_map->img_ptr_exit);
		mlx_destroy_image(my_map->mlx_ptr, my_map->img_ptr_pla);
		mlx_destroy_image(my_map->mlx_ptr, my_map->img_ptr_p);
		mlx_clear_window(my_map->mlx_ptr, my_map->win_ptr);
		mlx_destroy_window(my_map->mlx_ptr, my_map->win_ptr);
	}
	exit(1);
}
