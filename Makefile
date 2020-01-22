NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

SRC_DIR = srcs/

INC = includes/

OBJ = objects/

HEADER = $(INC)fillit.h\
	$(INC)sub.h\
	$(INC)check_input.h\
	$(INC)place.h\
	$(INC)print.h\
	$(INC)shift_bits.h\

SRCS = main.c\
	$(SRC_DIR)shift_bits.c\
	$(SRC_DIR)check_input.c\
	$(SRC_DIR)place.c\
	$(SRC_DIR)print.c\
	$(SRC_DIR)tet_algorithm.c\

all: $(NAME) $(SRCS)

$(NAME): $(SRCS) $(HEADER)
	make -C libft/
	$(CC) -o $(NAME) $(FLAGS) $(SRCS) -I./$(INC) -I./libft/ -L./libft/  -lft

compile: 
clean :
	@/bin/rm -f $(NAME)

re : clean all