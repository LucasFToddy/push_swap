NAME= push_swap.a

SRC = 	ft_strlcpy.c operations_stack.c stack_init.c \
	ft_atol.c ft_split.c ft_strlen.c ft_check_list.c ft_strjoin.c \
	moves_stack.c set_target.c inserts_list.c \
	order_stack.c rotate.c sort_stack.c sort_three.c \
	order_stack_b.c

CC= cc

CFLAG= -Wall -Wextra -Werror

OBJ= $(SRC:.c=.o)


$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

all: $(NAME) 
	$(CC) $(CFLAG) push_swap.c -o push_swap $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME) push_swap

re: fclean all 

run:
	clear
	$(CC) $(CFLAG) push_swap.c -o push_swap $(NAME)

.PHONY: all clean fclean re
