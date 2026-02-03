NAME := push_swap
CC := gcc
CFLAGS := -Wall -Werror -Wextra -Iinclude
RM := rm -rf
LIBFT := libft/libft.a
OBJDIR :=	obj
SRCDIR := src
SRC := \
	src/check_input.c src/index.c src/init.c src/push_swap.c \
	src/push.c src/rotate.c src/reverse_rotate.c src/sort.c \
	src/sort_radix.c src/swap.c src/utils.c

OBJ :=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

.PHONY : all re clean fclean

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@$(MAKE) clean -C libft
	$(RM) $(OBJDIR)

fclean: clean
	@$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all
