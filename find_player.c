/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:26:47 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/11 15:20:51 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	find_player(char **map, int len, t_map *my_map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] && i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				my_map->pos_player_x = i;
				my_map->pos_player_y = j;
			}
			j++;
		}
		i++;
	}
}
