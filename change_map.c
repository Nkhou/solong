/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:22:11 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/09 19:10:55 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int change_map(char **map, int x, int y, t_map *my_map)
{
	if (map[x][y] != '1')
	{
		if (map[x][y] == 'E' && my_map->nbr_c == 0)
		{
			my_map->map[x][y] = 'P';
			my_map->map[my_map->pos_player_x][my_map->pos_player_y] = '0';
			my_map->nbr_c = my_map->nbr_c - 1;
			printf("*******************\n     🎉🎉🎉🎉🎉🎉winner🥳🥳🥳🥳🥳\n				*******************");
			end_game(my_map);
		}
		else if (map[x][y] != 'E')
		{
			if (my_map->map[x][y] == 'C')
				my_map->nbr_c = my_map->nbr_c - 1;
			my_map->map[my_map->pos_player_x][my_map->pos_player_y] = '0';
			my_map->map[x][y] = 'P';
			my_map->x = my_map->pos_player_x;
			my_map->y = my_map->pos_player_y;
			my_map->pos_player_x = x;
			my_map->pos_player_y = y;
			// my_map->x = a;
			// my_map->y = b;
		}
			newone(my_map);
	}
	return (0);
}