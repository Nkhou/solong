/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:27:26 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/18 15:06:01 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	addi(char my_map, t_map *map)
{
	if (my_map == '0')
		add_earth(map);
	if (my_map != '\n')
		add_earth(map);
	if (my_map == 'P')
		add_player(map);
	if (my_map == 'E')
		add_exit(map);
	if (my_map == 'C')
		add_collectable(map);
	if (my_map == '1')
		add_wall(map);
}

int	dispaly_imag(t_map *my_map)
{
	int	i;
	int	j;

	i = 0;
	while (my_map->map[i] && i < my_map->len)
	{
		j = 0;
		while (my_map->map[i][j])
		{
			my_map->x = i;
			my_map->y = j;
			addi(my_map->map[i][j], my_map);
			j++;
		}
		i++;
	}
	mlx_key_hook(my_map->win_ptr, move_player, my_map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map_list;
	char	**my_map;

	my_map = NULL;
	if (argc == 2 && (ft_strrchr(argv[1], ".ber") != 0))
	{
		my_map = read_map(argv[1], my_map);
		map_list.map = read_map(argv[1], map_list.map);
		map_list.len = cmpt_line(map_list.map);
		if (map_list.len > 0)
			map_check(map_list, map_list.len);
		frre_table(map_list.map);
		map_list.map = my_map;
		map_list.nbr_c = cmpt_c(map_list, map_list.len);
		map_list.move = 0;
		map_list.width = 45;
		map_list.height = 45;
		map_list.imp_pos = 0;
		put_images(&map_list);
		mlx_hook(map_list.win_ptr, 17, 0, exit_map, NULL);
		mlx_loop(map_list.mlx_ptr);
	}
	else
		ft_error("Error in input\n");
	return (0);
}
