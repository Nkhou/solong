/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:41:22 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/12 17:32:02 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_element_of_map(char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != 'C') && (map[i][j] != 'P') && (map[i][j] != 'E')
				&& (map[i][j] != '1') && (map[i][j] != '0')
					&& (map[i][j] != '\n'))
			{
				ft_error("Error: map error\n");
			}
			j++;
		}
		i++;
	}
}
