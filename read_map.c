/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:21:04 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/12 17:10:21 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**read_map(char *str, char **my_map)
{
	char	*ma1;
	t_list	*map;
	int		fd;

	map = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Error : map not exist\n");
	while (1)
	{
		ma1 = get_next_line(fd);
		if (!ma1)
			break ;
		ft_lstadd_back(&map, ft_lstnew(ma1));
	}
	close(fd);
	check_map(map);
	my_map = copy_map(map, my_map);
	ft_lstclear(&map, free);
	return (my_map);
}
