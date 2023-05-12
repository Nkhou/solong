/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:40:48 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/12 11:07:12 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_collectible(t_map my_map, int len)
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
			if (my_map.map[i][j] == 'C')
				k++;
			j++;
		}
		i++;
	}
	if (k < 1)
		ft_error("collectible error\n");
}
