/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:27:26 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/28 15:06:54 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	**my_map;
	char	**my_ma;
	char	*ma1;
	t_list	*map;
	int		fd;
	int		i;
	int		len;

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
			if (!ma1)
				break ;
			ft_lstadd_back(&map, ft_lstnew(ma1));
		}
		check_map(map);
		len = ft_lstsize(map) * ft_strnline(map->content);
		my_map = (char **)malloc(sizeof(char *)*(len + 1));
		my_ma = (char **)malloc(sizeof(char *)*(len + 1));
		while (map)
		{
			my_map[i] = ft_strdup(map->content);
			my_ma[i] = ft_strdup(map->content);
			map = map->next;
			i++;
		}
		map_check(my_map, i);
		close(fd);
	}
}
