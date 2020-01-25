NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

SRC_DIR = srcs/

INC_DIR = includes/

LIBS_DIR = libft

LIBS = ft

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

HEADER = fillit.h

SRCS = shift_bits.c\
	tet_algorithm.c\
	check_input.c\
	print.c\
	place.c\
	sub.c\
	main.c

all: $(NAME)

lib :
	make -C libft/

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $(FLAGS) $(addprefix $(OBJ_DIR), $(SRCS:.c=.o)) -I./$(INC_DIR)  -L./libft -I./libft/ -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	$(CC) $(FLAGS) -o $@ -c $< -I./$(INC_DIR) -I./libft/ 

clean :
	make clean -C libft/
	/bin/rm -f $(OBJ) 


fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re : fclean all 