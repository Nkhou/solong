/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:42:24 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/12 11:24:51 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	valide_path(t_map my_map, int i, int j, int c)
{
	if (my_map.map[i][j] == '1' || (c == 0 && my_map.map[i][j] != 'E' )
		|| my_map.map[i][j] == '2' || my_map.map[i][j] == '\n')
		return ;
	else
	{
		if (my_map.map[i][j] != 'E' && c > 0)
		{
			if (my_map.map[i][j] == 'C')
				c--;
			if (my_map.map[i][j] != '\n')
				my_map.map[i][j] = '2';
			valide_path(my_map, i - 1, j, c);
			valide_path(my_map, i + 1, j, c);
			valide_path(my_map, i, j + 1, c);
			valide_path(my_map, i, j - 1, c);
		}
		else
			my_map.map[i][j] = '2';
	}
}
