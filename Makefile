NAME = ft_ls

SRC = main.c \

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	gcc $(OBJ) libft/libft.a -I libft -o $(NAME) $(GFLAGS)

%.o: %.c get_next_line/get_next_line.h
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

libft/libft.a:
	make -C libft
