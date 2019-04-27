
############
SOURCE	=	$(shell find . ! -name ".*" -name "*.c")
OBJ		=	$(notdir $(SOURCE:.c=.o))

all: $(OBJ)
	mv -f $(OBJ) ../

$(OBJ): $(SOURCE)
	gcc -c -Wall -Wextra -Werror $(SOURCE)

clean:
	@rm -f $(OBJ)

fclean: clean
	@cd .. && rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re