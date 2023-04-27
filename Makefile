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
		
OBJCTS = $(SRC:.c=.o)
all : $(NAME)
$(NAME) : $(OBJCTS)
		$(CC) $(OBJCTS) -o $@
%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJCTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re bonus