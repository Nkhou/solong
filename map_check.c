/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:47:17 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/28 15:34:19 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void wal(char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < len)
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if(map[0][j] != '1')
				ft_error("////no wall\n");
			if(map[len - 1][j] != '1')
				ft_error("////no wall\n");
			if(map[0][0] != '1')
				ft_error("***no wall\n");
			if(map[i][ft_strnline(map[i]) - 1] != '1')
				ft_error("---no wall%c\n");
			j++;
		}
		i++;
	}
}

void	map_check(char **map, int len)
{
	check_element_of_map(map, len);
	wal(map, len);
	check_players(map, len);
	check_collectible(map, len);
	path(map, len);
}