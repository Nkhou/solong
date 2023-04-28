/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:34:19 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/28 10:34:30 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_last_element(char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			ft_error("map error \n");
		i++;
	}
}