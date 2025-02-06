NAME= push_swap.a

SRC = 	ft_putstr.c ft_strlcpy.c operations_stack.c stack_init.c \
	ft_atoi.c ft_split.c ft_strlen.c ft_check_list.c ft_strjoin.c \
	moves_stack.c

CC= cc

CFLAG= -Wall -Wextra -Werror

OBJ= $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME) 

re: fclean all 

run:
	clear
	$(CC) $(CFLAG) main.c -o push_swap $(NAME)

.PHONY: all clean fclean re
