/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:47:17 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/14 18:06:22 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wal(t_map my_map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (my_map.map[i] && i < len)
	{
		j = 0;
		while (my_map.map[i][j] && my_map.map[i][j] != '\n')
		{
			if (my_map.map[0][j] != '1')
				ft_error("Error: \n no wall\n");
			if (my_map.map[len - 1][j] != '1')
				ft_error("Error: \n /no wall\n");
			if (my_map.map[0][0] != '1')
				ft_error("Error: \n no wall\n");
			if (my_map.map[i][ft_strnline(my_map.map[i]) - 1] != '1')
				ft_error("Error: \n no wall%c\n");
			j++;
		}
		i++;
	}
}

void	check_exit(t_map my_map, int len)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	k = 0;
	while (i < len)
	{
		j = 0;
		while (my_map.map[i][j])
		{
			if (my_map.map[i][j] == 'E')
				k++;
			j++;
		}
		i++;
	}
	if (k != 1)
		ft_error("Error: exit error\n");
}

void	map_check(t_map map, int len)
{
	wal(map, len);
	check_players(map, len);
	check_collectible(map, len);
	check_exit(map, len);
	path(map, len);
}
