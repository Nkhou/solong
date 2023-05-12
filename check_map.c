/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:36:10 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/12 17:32:02 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_list *map)
{
	int	l;

	l = ft_strnline(map->content);
	check_last_element((ft_lstlast(map))->content);
	map = map->next;
	while (map)
	{
		if (ft_strnline(map->content) != l)
			ft_error("Error: map not rectangulaire\n");
		map = map->next;
	}
}
