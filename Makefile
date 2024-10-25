CC		= cc
CFLAGS	= -Wall -Werror -Wextra #-fsanitize=address -g
NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c \
		input_check.c \
		initialization.c \
		stack.c \
		swap.c push.c rotate.c reverse_rotate.c \
		sort_tiny.c sort.c \
		position.c cost.c move.c \
		utils.c split.c utils_2.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))

OBJ		= $(SRC:.c=.o)

OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

INCS	= -I ./includes/

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJ_PATH) $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n                                                                                   "
	@echo "\033[95;1m ██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗  "
	@echo "\033[95;1m ██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗ "
	@echo "\033[95;1m ██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝ "
	@echo "\033[95;1m ██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝  "
	@echo "\033[95;1m ██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║      "
	@echo "\033[95;1m ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝      "
	@echo "\n                                                                                   "

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\nYour program got cleaned successfully\n"
	@if [ -f traces.txt ]; then rm -rf traces.txt; fi
	@if [ -f 0 ]; then rm -rf 0; fi

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re