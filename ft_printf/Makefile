CC := cc
FLAGS := --Wall --Wextra --Werror
RM := rm -f

LIBFT := ../libft
LIBFT_ARCHIVE := $(LIBFT)/libft.a
NAME := libftprintf.a

SRCS := ft_printf.c printchar.c puthex.c putptr.c putnbr.c putuint.c putstr.c

OBJS := $(SRCS:%.c=%.o)


%.o: %.c $(LIBFT_ARCHIVE)
	gcc -c $< -o $@

all: $(OBJS)
	cd $(LIBFT) && make
	cp $(LIBFT_ARCHIVE) $(NAME)
	ar rcs $(NAME) $^ 
	
clean: 
	cd $(LIBFT) && make clean
	$(RM) $(OBJS)

fclean: clean
	cd $(LIBFT) && make fclean
	$(RM) libft.a
	$(RM) $(NAME)

re: fclean all