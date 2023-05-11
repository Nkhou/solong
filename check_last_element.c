/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:34:19 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/11 15:18:17 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_last_element(char *map)
{
	int	i;

	i = ft_strnline(map);
	if (map[i] == '\n')
		ft_error("Error : no wall in map \n");
}
