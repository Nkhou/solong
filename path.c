/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:46:02 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/11 15:55:17 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	path(char **map, int len)
{
	char	**p;
	int		i;
	int		j;
	int		c;

	i = 0;
	p = map;
	while (i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				break ;
			j++;
		}
		if (map[i][j] == 'P')
			break ;
		i++;
	}
	c = cmpt_c(map, len);
	valide_path(p, i, j, c);
	check_path(p, len);
}
