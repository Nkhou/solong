/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:23:10 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/08 16:38:24 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	move_player(int keycode, t_map *my_map)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2 || keycode == 53 || keycode == 12 || (keycode >= 123 && keycode <= 126))
	{
		my_map->move = my_map->move + 1;
		if (keycode == 13 || keycode == 126)
		{
			my_map->imp_pos = 1; // up
			change_map(my_map->map, my_map->pos_player_x - 1, my_map->pos_player_y, my_map);
		}
		else if (keycode == 0 || keycode == 123)
		{
			my_map->imp_pos = 2; // lift
			change_map(my_map->map, my_map->pos_player_x , my_map->pos_player_y - 1, my_map);
		}
		else if (keycode == 1 || keycode == 125)
			change_map(my_map->map, my_map->pos_player_x + 1, my_map->pos_player_y, my_map);
		else if (keycode == 2 || keycode == 124)
		{
			my_map->imp_pos = 3; //down
			change_map(my_map->map, my_map->pos_player_x , my_map->pos_player_y + 1, my_map); //right
		}
		else if (keycode == 53 || keycode == 12)
				end_game(my_map);
		printf("%d\n", my_map->move);
	}
	return (0);
}