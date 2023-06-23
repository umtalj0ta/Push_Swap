CC       := gcc
CFLAGS   := -Wall -Werror -Wextra -g
NAME     := push_swap
PRINTF   := printf/libftprintf.a
SRC_PATH := src/
OBJ_PATH := obj/

SRC      := main.c \
            aux_linkedlists.c \
            swap.c \
            rotate.c \
			push.c \
			reverse_rotate.c \
			error_handling.c \
			sort.c \
			sort_aux.c \
			stack.c \
			position.c \
			move_cost.c \
			cost.c \
			utils.c \
			

SRCS     := $(addprefix $(SRC_PATH), $(SRC))
OBJ      := $(SRC:.c=.o)
OBJS     := $(addprefix $(OBJ_PATH), $(OBJ))
INCS     := -I ./includes

# Colors
RESET    := \033[0m
BOLD     := \033[1m
RED      := \033[31m
GREEN    := \033[32m
YELLOW   := \033[33m

all: $(OBJ_PATH) $(PRINTF) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(GREEN)Compiled:$(RESET) $(BOLD)$<$(RESET)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(PRINTF):
	@$(MAKE) -C printf
	@echo "$(GREEN)Libftprintf built$(RESET)"

$(NAME): $(OBJS) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) -I include $(PRINTF) -o $(NAME)
	@echo "$(BOLD)$(YELLOW)Executable '$(NAME)' created$(RESET)"

clean:
	@$(MAKE) -C printf clean
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)Object files removed$(RESET)"

fclean: clean
	@$(MAKE) -C printf fclean
	@rm -f $(NAME)
	@echo "$(RED)Executable '$(NAME)' removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re