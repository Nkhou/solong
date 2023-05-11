/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:16:47 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/11 15:20:48 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	end_game(t_map *my_map)
{
	int	i;

	i = 0;
	if (my_map != NULL)
	{	
		while (my_map->map[i])
		{
			free(my_map->map[i]);
			i++;
		}
		free(my_map->map);
		mlx_destroy_image(my_map->mlx_ptr, my_map->img_ptr_w);
		mlx_destroy_image(my_map->mlx_ptr, my_map->img_ptr_col);
		mlx_destroy_image(my_map->mlx_ptr, my_map->img_ptr_exit);
		mlx_destroy_image(my_map->mlx_ptr, my_map->img_ptr_pla);
		mlx_destroy_image(my_map->mlx_ptr, my_map->img_ptr_p);
		mlx_clear_window(my_map->mlx_ptr, my_map->win_ptr);
		mlx_destroy_window(my_map->mlx_ptr, my_map->win_ptr);
	}
	free(my_map->mlx_ptr);
	exit(0);
}
