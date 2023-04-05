/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:27:26 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/05 01:25:45 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_map(t_list *map)
{
	t_sizelist	*L;
	int			l;

	l = ft_lstsize(map);
	while (map)
	{
		L->content = ft_strlen(map->content);
		map = map->next;
		L = L->next;
	}
}

int	main(int argc, char **argv)
{
	char	*ma1;
	t_list	*map;
	int		fd;
	int		i;

	i = 0;
	(void)argv;
	map = NULL;
	if (argc == 1)
	{
		fd = open("map.txt", O_RDONLY);
		if (fd == -1)
			return (0);
		while (1)
		{
			ma1 = get_next_line(fd);
			ft_lstadd_back(&map, ft_lstnew(ma1));
			if (!ma1)
				break ;
		}
		check_map(map);
		close(fd);
	}
}
