/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:47:17 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/23 20:03:52 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_protect(t_map my_map)
{
	int	len;

	len = ft_strlen(my_map.map[0]);
	if (len * 45 > 1550 * 5 || my_map.len * 45 > (2880 * 5))
		ft_error("Error :size map\n");
}

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
				ft_error("Error: no wall\n");
			if (my_map.map[len - 1][j] != '1')
				ft_error("Error: no wall\n");
			if (my_map.map[i][0] != '1')
				ft_error("Error: no wall\n");
			if (my_map.map[i][ft_strnline(my_map.map[i]) - 1] != '1')
				ft_error("Error: no wall\n");
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

void	check(t_map my_map)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	k = 0;
	while (i < my_map.len)
	{
		j = 0;
		while (my_map.map[i][j])
		{
			if (my_map.map[i][j] != '1' && my_map.map[i][j] != '\n'
				&& my_map.map[i][j] != 'E' && my_map.map[i][j] != '0'
					&& my_map.map[i][j] != 'C' && my_map.map[i][j] != 'P')
			{
				ft_error("Error: wrong map\n");
			}
			j++;
		}
		i++;
	}
}

void	map_check(t_map map, int len)
{
	check(map);
	wal(map, len);
	check_players(map, len);
	check_collectible(map, len);
	check_exit(map, len);
	ft_protect(map);
	path(map, len);
}
