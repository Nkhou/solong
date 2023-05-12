/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:43:18 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/12 11:29:15 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
				&& my_map.map[i][j] != '2')
			{
				ft_error("path error\n");
			}
			j++;
		}
		i++;
	}
}
