/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:43:18 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/17 20:29:03 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_map my_map, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (my_map.map[i][j])
		{
			if (my_map.map[i][j] != '1' && my_map.map[i][j] != '\n'
				&& my_map.map[i][j] != '2' && my_map.map[i][j] != '0')
			{
				ft_error("Error: path error\n");
			}
			j++;
		}
		i++;
	}
}
