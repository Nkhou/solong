/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:46:02 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/12 17:32:02 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path(t_map my_map, int len)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (my_map.map[i][j])
		{
			if (my_map.map[i][j] == 'P')
				break ;
			j++;
		}
		if (my_map.map[i][j] == 'P')
			break ;
		i++;
	}
	c = cmpt_c(my_map, len);
	valide_path(my_map, i, j, c);
	check_path(my_map, len);
	i = 0;
}
