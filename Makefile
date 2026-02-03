NAME := push_swap
CC := gcc
CFLAGS := -Wall -Werror -Wextra 
RM = rm -f
LIBFTDIR := libft/
OBJDIR :=	obj/
SRCDIR := srcs/
OBJ :=$($(OBJDIR),$(SRC:.c=.o))
INCLUDE := -L ./libft -lft

.PHONY : all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
