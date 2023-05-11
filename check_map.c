/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:36:10 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/11 16:07:25 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_map(t_list *map)
{
	int	l;

	l = ft_strnline(map->content);
	check_last_element((ft_lstlast(map))->content);
	map = map->next;
	while (map)
	{
		if (ft_strnline(map->content) != l)
			ft_error("map not rectangulaire***********\n");
		map = map->next;
	}
}
