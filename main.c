/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:27:26 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/25 19:17:34 by nkhoudro         ###   ########.fr       */
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
void check_exit(char **map, int len)
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
			if (map[i][j] == 'E')
				k++;
			j++;
		}
		i++;
	}
	if (k != 1)
		ft_error("Exit error\n");
}
void check_collectible(char **map, int len)
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
			if (map[i][j] == 'C')
				k++;
			j++;
		}
		i++;
	}
	if (k < 1)
		ft_error("collectible error\n");
}
void check_element_of_map(char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
				ft_error("map error\n");
			j++;
		}
		i++;
	}
}
void	valide_path(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == '2' || (map[i][j] != 'E'))
		return ;
	else
	{
			map[i][j] = '2';
			valide_path(map, i - 1, j);
			valide_path(map, i + 1, j);
			valide_path(map, i, j + 1);
			valide_path(map, i , j - 1);
	}
}
void check_path(char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	while(i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '\n' && map[i][j] != '2')
			{
				printf("%c\n", map[i][j]);
				ft_error("path error\n");
			}
			j++;
		}
		i++;
	}
}
void make_one(char **map,int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '\n')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}
void valide_path_exit(char **map, int i, int j, int len)
{
	if (map[i][j] == '1')
		return ;
	else
	{
		if (map[i][j] == 'E')
		{
			map[i][j] = '2';
			i = 0;
			exit(1);
			check_path(map, len);
			// make_one(map, len);
			return ;
		}
		else
		{
			valide_path_exit(map, i - 1, j, len);
			valide_path_exit(map, i + 1, j, len);
			valide_path_exit(map, i, j + 1, len);
			valide_path_exit(map, i , j - 1, len);
		}
	}
}
void path(char **map, int len)
{
	char **p;
	int	i;
	int	j;

	i = 0;
	p = map;

	while(i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				break;
			j++;
		}
		if (map[i][j] == 'P')
				break;
		i++;
	}
	valide_path(p, i, j);
	valide_path_exit(p, i, j, len);
}
void	map_check(char **map, int len)
{
	check_element_of_map(map, len);
	wall(map, len);
	check_players(map, len);
	check_exit(map, len);
	check_collectible(map, len);
	path(map, len);
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
