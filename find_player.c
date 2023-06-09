/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:26:47 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/12 17:32:02 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
