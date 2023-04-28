/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:42:24 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/28 10:42:34 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	valide_path(char **map, int i, int j, int c)
{
	if (map[i][j] == '1' || (c == 0 && map[i][j] != 'E' ) || map[i][j] == '2' || map[i][j] == '\n')
		return ;
	else
	{
		if (map[i][j] != 'E' && c > 0)
		{
			if (map[i][j] == 'C')
				c--;
			if (map[i][j] !='\n')
				map[i][j] = '2';
			valide_path(map, i - 1, j, c);
			valide_path(map, i + 1, j, c);
			valide_path(map, i, j + 1, c);
			valide_path(map, i , j - 1, c);
		}
		else
		{
			map[i][j] = '2';
		}
	}
}