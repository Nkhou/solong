/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:27:26 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/23 16:20:26 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	check_map(t_list *map)
{
	int l;
	l = ft_strnline(map->content);
	map = map->next;
	while (map)
	{
		if (ft_strnline(map->content) != l) // last line
			ft_error("map not rectangulaire***********\n");
		map = map->next;
	}
}
void wall(char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < len)
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if(map[0][j] != '1')
				ft_error("////no wall\n");
			if(map[len - 1][j] != '1')
				ft_error("////no wall\n");
			if(map[0][0] != '1')
				ft_error("***no wall\n");
			if(map[i][ft_strnline(map[i]) - 1] != '1')
				ft_error("---no wall%c\n");
			j++;
		}
		i++;
	}
}
void check_players(char **map, int len)
{
	int	i;
	int k;
	int	j;

	i = 0;
	j = 0;
	k = 0;
	while(i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				k++;
			j++;
		}
		i++;
	}
	if (k != 1)
		ft_error("player error\n");
}
void	map_check(char **map, int len)
{
	wall(map, len);
	check_players(map, len);
}
 
int	main(int argc, char **argv)
{
	char	**my_map;
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
		while (map)
		{
			my_map[i] = ft_strdup(map->content);
			map = map->next;
			i++;
		}
		map_check(my_map, i);
		close(fd);
	}
}
