/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:00:41 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/11 15:53:52 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newone(t_map *my_map)
{
	my_map->map[my_map->pos_player_x][my_map->pos_player_y] = '0';
	add_earth(my_map);
	my_map->x = my_map->pos_player_x;
	my_map->y = my_map->pos_player_y;
	add_earth(my_map);
	ajou_player(my_map);
	return (0);
}

int	ajou_player(t_map *my_map)
{
	my_map->map[my_map->pos_player_x][my_map->pos_player_y] = 'P';
	addi(my_map->map[my_map->pos_player_x][my_map->pos_player_y], my_map);
	return (0);
}
