NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/

INC_DIR = includes/

LIBS_DIR = libft

LIBS = ft

OBJ = objects/


HEADER = fillit.h\
	sub.h\
	check_input.h\
	place.h\
	print.h\
	shift_bits.h\

SRCS = main.c\
	shift_bits.c\
	check_input.c\
	place.c\
	print.c\
	tet_algorithm.c\

#all: $(NAME) $(addprefix $(SRC_DIR),$(SRCS)) $(addprefix $(INC_DIR)/,$(HEADER))
all: $(NAME) $(addprefix $(SRC_DIR),$(SRCS))

#$(NAME): $(addprefix $(SRC_DIR),$(SRCS)) $(addprefix $(INC_DIR)/,$(HEADER))
#$(NAME): shift_bits.o check_input.o place.o print.o tet_algorithm.o
#	make -C $(LIBS_DIR)
#	$(CC) $(FLAGS) -c $(addprefix $(SRC_DIR),$(SRCS)) $(addprefix -I./,$(INC_DIR)) -I./libft
#	gcc -o $(name) $(FLAGS) main.c $(SRCS:.c=.o) -I./$(INC_DIR)  -L./libft -I./libft/ -lft

$(NAME) : $(SRCS:.c=.o) 
	$(CC) -o $(NAME) $(FLAGS) $(SRCS:.c=.o) -I./$(INC_DIR)  -L./libft -I./libft/ -lft
	$(CC) $(FLAGS) -c -I./$(INC_DIR) -I./libft $(addprefix $(SRC_DIR),$(SRCS))

#$(SRCS:.c=.o) :
#	$(CC) $(FLAGS) -c -I./$(INC_DIR) -I./libft $(addprefix $(SRC_DIR),$(SRCS))


clean :
	@/bin/rm -f $(SRCS:.c=.o) 

fclean: clean
	@/bin/rm -f $(NAME)

re : fclean all 