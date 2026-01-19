# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 13:56:23 by dbobrov           #+#    #+#              #
#    Updated: 2025/11/19 13:56:23 by dbobrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -I.

AR			:= ar rcs
RM			:= rm -f

SRC_DIR		:= .

SRCS    := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
           ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
           ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
           ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
           ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
           ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
           ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
           ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
           ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

B_SRCS  := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
           ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
           ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS		:= $(SRCS:%.c=%.o)
B_OBJS		:= $(B_SRCS:%.c=%.o)
DEPS		:= $(OBJS:.o=.d) $(B_OBJS:.o=.d)

GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
RED			:= \033[0;31m
RESET		:= \033[0m

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)[Archiving]$(RESET) $(NAME)"
	@$(AR) $@ $^
	@echo "$(GREEN)[OK] Library built successfully!$(RESET)"

bonus: $(OBJS) $(B_OBJS)
	@echo "$(YELLOW)[Archiving Bonus]$(RESET) $(NAME)"
	@$(AR) $(NAME) $(B_OBJS)
	@echo "$(GREEN)[OK] Bonus library built successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
	@echo "$(GREEN)[Compiled]$(RESET) $<"

-include $(DEPS)

clean:
	@echo "$(RED)[Cleaning objects...]$(RESET)"
	@$(RM) $(OBJS) $(B_OBJS) $(DEPS)

fclean: clean
	@echo "$(RED)[Removing library...]$(RESET)"
	@$(RM) $(NAME)

re: fclean all

norm:
	@echo "$(YELLOW)[Running Norminette...]$(RESET)"
	@norminette $(SRCS) $(B_SRCS)
	@echo "$(GREEN)[OK] Norminette check finished!$(RESET)"
