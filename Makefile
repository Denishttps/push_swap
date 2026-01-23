NAME := push_swap
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR := ft_printf
FT_PRINTF := $(FT_PRINTF_DIR)/libftprintf.a

SRCS_DIR := src
SRCS := $(SRCS_DIR)/push_swap.c \
        $(SRCS_DIR)/utils.c \
        $(SRCS_DIR)/parser.c \
        $(SRCS_DIR)/algo/bubble_sort.c \
        $(SRCS_DIR)/algo/sort_three.c \
        $(SRCS_DIR)/algo/sort_stack.c \
        $(SRCS_DIR)/algo/is_sorted.c \
        $(SRCS_DIR)/algo/move_node.c \
        $(SRCS_DIR)/algo/utils.c \
        $(SRCS_DIR)/ops/op_push.c \
        $(SRCS_DIR)/ops/op_rotate.c \
        $(SRCS_DIR)/ops/op_swap.c \
        $(SRCS_DIR)/ops/op_reverse_rotate.c \
        $(SRCS_DIR)/stack/stack_add_back.c \
        $(SRCS_DIR)/stack/stack_add_front.c \
        $(SRCS_DIR)/stack/stack_last.c \
        $(SRCS_DIR)/stack/stack_new.c \
        $(SRCS_DIR)/stack/stack_size.c \
        $(SRCS_DIR)/stack/stack_clear.c \
        $(SRCS_DIR)/stack/stack_set_index.c \
        $(SRCS_DIR)/stack/stack_set_pos.c \
        $(SRCS_DIR)/stack/stack_set_costs.c \
        $(SRCS_DIR)/stack/stack_set_target_node.c \

OBJS := $(SRCS:.c=.o)
HEADER := -Iincludes -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)


all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
