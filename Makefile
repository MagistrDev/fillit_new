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

all: $(NAME)	

$(NAME): $(SRCS) $(HEADER)
	$(CC) -o $(NAME) $(FLAGS) $(SRCS) -I./$(INC)

clean :
	@/bin/rm -f $(NAME)
#	del $(NAME).exe
re : clean all