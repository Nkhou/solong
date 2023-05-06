/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:27:26 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/06 14:40:51 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 int dispaly_imag(t_map *my_map);
 int put_images(t_map *map);
int cmpt_line(char **map)
{
	int	i;

	i = 0;
	while(map[i])
		i++;
	return (i);
}
char	**copy_map(t_list *map, char **my_map)
{
	int len;
	int i;

	i = 0;
	len = ft_lstsize(map) * ft_strnline(map->content);
	my_map = (char **)malloc(sizeof(char *)*(len + 1));
	while (map)
	{
		my_map[i] = ft_strdup(map->content);
		map = map->next;
		i++;
	}
	my_map[i] = NULL;
	return(my_map);
}
char **read_map(char *str, char **my_map)
{
	char	*ma1;
	t_list	*map;
	int	fd;
	map = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
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
	return (my_map);
}
int change_map(char **map, int x, int y, t_map *my_map)
{
	if (map[x][y] != '1')
	{
		if (map[x][y] == 'E' && my_map->nbr_c == 0)
		{
			my_map->map[x][y] = 'P';
			my_map->map[my_map->pos_player_x][my_map->pos_player_y] = '0';
			my_map->nbr_c = my_map->nbr_c - 1;
			mlx_destroy_window(my_map->mlx_ptr, my_map->win_ptr);
			dispaly_imag(my_map);
			put_images(my_map);
		}
		else if (my_map->map[x][y] == 'C')
		{
			my_map->map[x][y] = 'P';
			my_map->map[my_map->pos_player_x][my_map->pos_player_y] = '0';
			my_map->nbr_c = my_map->nbr_c - 1;
			mlx_destroy_window(my_map->mlx_ptr, my_map->win_ptr);
			put_images(my_map);
		}
		else if (map[x][y] == '0')
		{
			my_map->map[x][y] = 'P';
			my_map->map[my_map->pos_player_x][my_map->pos_player_y] = '0';
			mlx_clear_window(my_map->mlx_ptr, my_map->win_ptr);
			put_images(my_map);
		}
	}
	return (0);
}
int	move_player(int keycode, t_map *my_map)
{
	(void)my_map;
	if (keycode == 13)
	{
		change_map(my_map->map, my_map->pos_player_x - 1, my_map->pos_player_y, my_map);
		printf("ana w\n");
	}
	else if (keycode == 0)
	{
		
		change_map(my_map->map, my_map->pos_player_x , my_map->pos_player_y - 1, my_map);
		printf("ana a\n");
	}
	else if (keycode == 1)
	{
		
		change_map(my_map->map, my_map->pos_player_x + 1, my_map->pos_player_y, my_map);
		printf("ana s\n");
	}
	else if (keycode == 2)
	{
		change_map(my_map->map, my_map->pos_player_x , my_map->pos_player_y + 1, my_map);
		printf("ana d\n");
	}
	return (0);
}
void addi(char my_map, t_map *map)
{

	int h;
	int w;

	h = 45;
	w = 45;
	if (my_map != '\n')
	{
		map->img_ptr_pla = mlx_xpm_file_to_image(map->mlx_ptr, "sur.xpm", &w, &h);
 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_pla, map->y * h, map->x * w);
	}
	if (my_map == 'P')
	{
		map->img_ptr_p = mlx_xpm_file_to_image(map->mlx_ptr, "super_mario.xpm", &w, &h);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_p, map->pos_player_y * h, map->pos_player_x * w );
	}
	if (my_map == 'E')
	{
		map->img_ptr_exit = mlx_xpm_file_to_image(map->mlx_ptr, "black-hol.xpm", &w, &h);
		
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_exit,  map->y * h, map->x * w);
	}
	if (my_map == '1')
	{
		map->img_ptr_w = mlx_xpm_file_to_image(map->mlx_ptr, "wal.xpm", &w, &h);
		
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_w, map->y * h, map->x * w);
	}
	if (my_map == '0')
	{
		map->img_ptr_pla = mlx_xpm_file_to_image(map->mlx_ptr, "sur.xpm", &w, &h);
 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_pla, map->y * h, map->x * w);
	}
	if (my_map == 'C')
	{
		map->img_ptr_col = mlx_xpm_file_to_image(map->mlx_ptr, "treasure.xpm", &w, &h);
		
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_col, map->y * h, map->x * w);
	}
	mlx_key_hook(map->win_ptr,move_player, map);
}

 int dispaly_imag(t_map *my_map)
{
	int i;
	int j;
	
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
	mlx_loop(my_map->mlx_ptr);
	return (0);
}
void find_player(char **map, int len, t_map *my_map)
{
	int i;
	int j;
	
	i = 0;
	while (map[i] && i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				my_map->pos_player_x = i;
				my_map->pos_player_y = j;
				
			}
			j++;
		}
		i++;
	}
}
int put_images(t_map *map)
{
	// void *mlx_ptr;
    // void *win_ptr;
	int width = 1530;
	int height = 270;

	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, width, height, "so_long");

	find_player(map->map, map->len, map);
	dispaly_imag(map);
	return (0);
}
int	main(int argc, char **argv)
{
	t_map map_list;
	char	**my_map;
	int		i;

	my_map = NULL;
	//map_list = NULL;
	if (argc == 2)
	{
		my_map = read_map(argv[1], my_map);
		i = cmpt_line(my_map);

		if (i > 0)
			map_check(my_map, i);
		map_list.map = read_map(argv[1], map_list.map);
		map_list.nbr_c =cmpt_c(map_list.map, i);
		map_list.len = i;
		
		put_images(&map_list);
		// Create a window

		// Load the image
		// Loop to keep the window open
	}
	return (0);
}

