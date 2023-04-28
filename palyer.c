/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palyer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:38:34 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/28 10:38:47 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void check_players(char **map, int len)
{
	int	i;
	int k;
	int	j;

	i = 0;
	j = 0;
	k = 0;
	while(i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				k++;
			j++;
		}
		i++;
	}
	if (k != 1)
		ft_error("player error\n");
}