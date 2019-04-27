NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER = ft_printf_hd.h

CFILES = ft_printf_format.c \
		get_flags_ftpf.c \
		 parse_flags.c \
		 ft_printf_char.c \
		 padding_ints.c \
		 printf_decimals.c \
		 ft_number_len.c	\
		itoa_base_pf.c \
		float_conversion_printf.c \
		unsigned_ints_printf.c \
		printf_pointers.c \
		printf_strings.c \
		print_hexadec.c \
		printf_percent_sign.c \
		printf_floats.c \
		octal_printf.c
		#libft_ftprintf_2.c \
		#libft_ft_printf.c 

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c -I.$(HEADER) $(CFILES)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
