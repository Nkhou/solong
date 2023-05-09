/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:22:11 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/09 21:53:41 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int change_map(char **map, int x, int y, t_map *my_map)
{
	if (map[x][y] != '1')
	{
		my_map->move = my_map->move + 1;
		if (map[x][y] == 'E' && my_map->nbr_c == 0)
		{
			my_map->map[x][y] = 'P';
			my_map->map[my_map->pos_player_x][my_map->pos_player_y] = '0';
			my_map->nbr_c = my_map->nbr_c - 1;
			ft_putstr_fd("*******************\n     🎉🎉🎉🎉🎉🎉winner🥳🥳🥳🥳🥳\n				*******************", 1);
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
		}
		ft_putstr_fd("number of moving :", 1);
		ft_putnbr_fd(my_map->move, 1);
		ft_putstr_fd("\n", 1);
			newone(my_map);
	}
	return (0);
}