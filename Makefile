NAME = ft_ls

SRC = main.c \
	  flags.c \
	  rwx.c \
	  time.c \
	  admin_folder.c \
	  print.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): libft/libft.a $(OBJ) ls.h
	gcc $(OBJ) libft/libft.a -I libft -o $(NAME) $(GFLAGS)

%.o: %.c ls.h
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
