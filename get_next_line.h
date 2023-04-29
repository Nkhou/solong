/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:45:27 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/29 18:00:43 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

typedef struct s_sizelist
{
	int					content;
	struct s_sizelist	*next;
}	t_sizelist;

typedef struct s_data
{
	void	*img;
	char *addr;
	int bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
char	*ft_strdup(char *s1);
int	ft_strnline( char *s);
void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(char *s1, char s2);
void ft_error(char *str);
void	check_last_element(char *map);
void	check_map(t_list *map);
void check_players(char **map, int len);
void check_collectible(char **map, int len);
void check_element_of_map(char **map, int len);
void	valide_path(char **map, int i, int j, int c);
void check_path(char **map, int len);
int cmpt_c(char **map, int len);
void path(char **map, int len);
void	map_check(char **map, int len);

#endif
