/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:27:26 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/05 20:54:28 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

// void	move_player(int keycode, void *win_ptr, char **map)
// {
// 	printf("%d\n", keycode);
// }
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
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr_p, map->y * h, map->x * w );
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
	// mlx_key_hook(map->win_ptr,move_player, img_ptr_p);
}

void dispaly_image(char **map, int len, t_map *my_map)
{
	int i;
	int j;
	
	i = 0;
	while (map[i] && i < len)
	{
		j = 0;
		while (map[i][j])
		{
			my_map->x = i;
			my_map->y = j;
			addi(map[i][j], my_map);
			j++;
		}
		i++;
	}
	mlx_loop(my_map->mlx_ptr);
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
void put_images(t_map *map, int len)
{
	// void *mlx_ptr;
    // void *win_ptr;
	int width = 1530;
	int height = 270;

	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, width, height, "so_long");

	find_player(map->map, len, map);
	dispaly_image(map->map, len, map);
}
int	main(int argc, char **argv)
{
	t_map *map_list;
	char	**my_map;
	int		i;

	my_map = NULL;
	map_list = NULL;
	if (argc == 2)
	{
		my_map = read_map(argv[1], my_map);
		i = cmpt_line(my_map);

		if (i > 0)
			map_check(my_map, i);
		map_list->map = read_map(argv[1], map_list->map);
		put_images(map_list, i);
		// Create a window

		// Load the image
		// Loop to keep the window open
	}
	return (0);
}






// int checkKeys(int key, char *t) {
// 	printf("%d    %s\n", key,t);
// 		if (key == 53)
// 			exit(1);
// 	return 0;
// }
// int main()
// {
//     void *mlx_ptr;
//     void *win_ptr;
//     void *img_ptr;
//     int width = 2000;
//     int height = 2000;

//     // Initialize mlx
//     mlx_ptr = mlx_init();

//     // Create a window
//     win_ptr = mlx_new_window(mlx_ptr, width, height, "My Window");

//     // Load the image
//     img_ptr = mlx_xpm_file_to_image(mlx_ptr, "img.xpm", &width, &height);
// 	printf("%s\n", img_ptr);
//     // Draw the image
// 	mlx_hook(win_ptr,2,3, checkKeys, "");
//     // Loop to keep the window open
//     mlx_loop(mlx_ptr);

//     return 0;
// }
