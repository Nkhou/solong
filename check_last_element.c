/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:34:19 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/29 18:58:53 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_last_element(char *map)
{
	int i;

	i = 0;
	i = ft_strnline(map);
	if (map[i] == '\n')
	{
		printf("*****%c*******\n", map[i]);
		ft_error("map error \n");
	}
}