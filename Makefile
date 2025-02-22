NAME= push_swap
PATH_PRINTF=./ft_printf/
PRINTF=./ft_printf/ft_printf.a

SRC = 	ft_strlcpy.c operations_stack.c stack_init.c \
	ft_atol.c ft_split.c ft_strlen.c ft_check_list.c ft_strjoin.c \
	moves_stack.c set_target.c inserts_list.c \
	order_stack.c rotate.c sort_stack.c sort_three.c \
	order_stack_b.c ft_putendl_fd.c push_swap.c

CC= cc

CFLAG= -g -Wall -Wextra -Werror

OBJ= $(SRC:.c=.o)

all: $(PRINTF) $(NAME)

.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(PRINTF) -o $(NAME)

$(PRINTF): 
	@make -C $(PATH_PRINTF)

clean:
	rm -rf $(OBJ)
	@make -C $(PATH_PRINTF) fclean

fclean:clean
	rm -rf $(NAME) push_swap
	@make -C $(PATH_PRINTF) fclean

re: fclean all 


.PHONY: all clean fclean re
