/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:20:19 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/11 15:20:58 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**copy_map(t_list *map, char **my_map)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(map) * ft_strnline(map->content);
	my_map = (char **) malloc(sizeof(char *) * (len + 1));
	while (map)
	{
		my_map[i] = ft_strdup(map->content);
		map = map->next;
		i++;
	}
	my_map[i] = NULL;
	return (my_map);
}
