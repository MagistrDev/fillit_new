NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/

INC = ./includes/

OBJ = objects/

SRCS = main.c\
	$(SRC_DIR)shift_bits.c\
	$(SRC_DIR)check_input.c\
	$(SRC_DIR)place.c\
	$(SRC_DIR)print.c\
	$(SRC_DIR)tet_algorithm.c\

#all: $(NAME)

all: $(NAME)	

$(NAME): $(SRCS)
	$(CC) -o $(NAME) $(FLAGS) $(SRCS) -I$(INC)

clean :
	@/bin/rm -f $(NAME)

re : clean all