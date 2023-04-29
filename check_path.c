/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:43:18 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/29 18:07:38 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void check_path(char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	while(i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '\n' && map[i][j] != '2')
			{
				ft_error("path error\n");
			}
			j++;
		}
		i++;
	}
}