/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:27:26 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/29 21:08:31 by nkhoudro         ###   ########.fr       */
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
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x *(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	main(int argc, char **argv)
{
	char	**my_map;
	t_data 	img;
	void	*mlx;
	void	*mlx_win;
	int		i;

	my_map = NULL;
	if (argc == 2)
	{
		my_map = read_map(argv[1], my_map);
		i = cmpt_line(my_map);
		// int j;

		// j = 0;
		// while ()
		if (i > 0)
			map_check(my_map, i);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 199, 200, "hello world");
		img.img = mlx_new_image(mlx,199, 200);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}
	return (0);
}

