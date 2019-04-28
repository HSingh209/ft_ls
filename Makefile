NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_ls_hd.h

CFILES = *.c

OFILES = *.o

LIBFT = libft.a

LCFILES = ./libft/*.c \
		  ./libft/assets/ft_printf/*.c

LOFILES = ./*.o

LHEADER = libft/libft.h

all: $(NAME)

$(NAME): $(LOFILES)
	ar rc $(LIBFT) $(LOFILES)
	ranlib $(LIBFT)
	$(CC) $(CFLAGS) -I=$(HEADER) -o $(NAME) $(CFILES) $(LIBFT)

$(LOFILES): $(LCFILES)
	$(CC) -c $(CFLAGS) -I=$(LHEADER) $(LCFILES)

clean:
	rm -rf $(OFILES) $(LOFILES)

fclean:
	rm -rf $(NAME) $(LIBFT) $(OFILES) $(LOFILES)

re: fclean all

.PHONY: clean fclean all re
