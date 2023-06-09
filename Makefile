CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror 
SRC = \
		main.c\
		ft_lstadd_back.c\
		ft_lstlast.c\
		ft_lstnew.c\
		get_next_line.c \
		get_next_line_utils.c\
		ft_lstsize.c\
		ft_strnline.c\
		ft_putstr.c\
		ft_strcmp.c\
		collectible.c\
		ft_error.c\
		ft_strlen.c\
		map_check.c\
		check_element_map.c\
		check_last_element.c\
	    palyer.c\
		check_map.c\
	    path.c\
		check_path.c\
		valide_path.c\
		cmpt_c.c\
		ft_lstclear.c\
		put_image.c\
		end_game.c\
		cmpt_line.c\
		copy_map.c\
		read_map.c\
		change_map.c\
		move_player.c\
		add_image.c\
		find_player.c\
		newone.c\
		ft_putnbr.c\
		ft_putchar.c\
		ft_findstring.c\
		inistial_image.c\
		free_table.c\
	
OBJCTS = $(SRC:.c=.o)
all : $(NAME)
$(NAME) : $(OBJCTS) 
		$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $^ -o $@
%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean:
	rm -f $(OBJCTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re bonus
