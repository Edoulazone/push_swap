CC		= cc
CFLAGS	= -Wall -Werror -Wextra #-fsanitize=address -g
NAME	= push_swap

SRC_PATH = srcs/
OBJ_PATH = obj/

SRC = 	main.c \
		parsing.c \
		parsing_utils.c \
		split.c \
		utils.c \
		utils_2.c \
		stack_operations.c \
		basic_operations.c \
		push_operations.c \
		rotate_operations.c \
		reverse_rotate_operations.c \
		stack_analysis.c \
		sorting.c \
		sorting_large.c \
		cost_calculation.c \
		cost_calculation_utils.c \
		move_execution.c \
		advanced_cost.c \
		advanced_cost_utils.c \
		pattern_detection.c \
		pattern_detection_utils.c \
		move_optimization.c \
		move_optimization_utils.c

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