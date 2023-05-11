/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:23:10 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/11 16:11:27 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	mv_pl(int x, int y, t_map *my_map, int pos)
{
	my_map->imp_pos = pos;
	change_map(my_map->map, x, y, my_map);
}

int	move_player(int keycode, t_map *my_map)
{
	if (keycode == 13 || keycode == 0 || keycode == 1
		|| keycode == 2 || keycode == 53 || keycode == 12
		|| (keycode >= 123 && keycode <= 126))
	{
		if (keycode == 13 || keycode == 126)
			mv_pl(my_map->pos_player_x - 1,
				my_map->pos_player_y, my_map, 1);
		else if (keycode == 0 || keycode == 123)
			mv_pl(my_map->pos_player_x,
				my_map->pos_player_y - 1, my_map, 2);
		else if (keycode == 1 || keycode == 125)
			mv_pl(my_map->pos_player_x + 1,
				my_map->pos_player_y, my_map, 0);
		else if (keycode == 2 || keycode == 124)
			mv_pl(my_map->pos_player_x,
				my_map->pos_player_y + 1, my_map, 3);
		else if (keycode == 53 || keycode == 12)
			end_game(my_map);
	}
	return (0);
}
