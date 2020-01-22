NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/

INC_DIR = includes/

LIBS_DIR = libft

LIBS = ft

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

HEADER = fillit.h\
	sub.h\
	check_input.h\
	place.h\
	print.h\
	shift_bits.h\

SRCS = shift_bits.c\
	tet_algorithm.c\
	check_input.c\
	print.c\
	place.c\
	main.c

all: lib $(NAME)

lib :
	make -C libft/

$(NAME) : $(addprefix includes/,$(HEADER)) $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(addprefix $(OBJ_DIR), $(SRCS:.c=.o)) -I./$(INC_DIR)  -L./libft -I./libft/ -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)%.h 
	$(CC) $(FLAGS) -o $@ -c $< -I./$(INC_DIR) -I./libft/ 

clean :
	/bin/rm -f $(OBJ) 


fclean: clean
	/bin/rm -f $(NAME)

re : fclean all 