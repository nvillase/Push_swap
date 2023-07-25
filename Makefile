SRC = ./srcs/main.c ./srcs/checks.c ./srcs/utils.c ./srcs/instructions.c ./srcs/num_utils.c ./srcs/algo.c
BSRCS = ./srcs/bonus/checker.c ./srcs/bonus/silent_instructions.c ./srcs/checks.c ./srcs/utils.c ./srcs/instructions.c ./srcs/num_utils.c ./srcs/algo.c
	
OBJS = $(SRC:.c=.o)
BOBJS = $(BSRCS:.c=.o)
RM = rm -f
NAME = push_swap
BNAME = checker
LIB = ./includes/libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g


all : author ${LIB} $(NAME)

bonus : author ${LIB} $(NAME) $(BNAME)

${LIB} :
	@make -s -C ./includes/libft/ all
	@echo Libft is ready.

author :
	@echo "Author :\tnvillase"
	@echo "Project :\t$(NAME)"
	@echo ---------------------------------------------------------

PRINT_NAME = 1

%.o: %.c
	@if [ $(PRINT_NAME) -eq 1 ]; then echo -n "$(NAME) : "; fi
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n "\033[32m✔\033[0m"
	@$(eval PRINT_NAME = 0)

$(NAME) : $(OBJS) ${LIB}
	@${CC} ${CFLAGS} $(OBJS) -L./includes/libft -lft -o $(NAME)
	@echo
	@echo $(NAME) is runnable.

$(BNAME) : $(BOBJS) ${LIB}
	@${CC} ${CFLAGS} $(BOBJS) -L./includes/libft -lft -o $(BNAME)
	@echo
	@echo $(BNAME) is runnable.

clean :
	@${RM} ${OBJS} ${BOBJS}
	@make -s -C ./includes/libft/ clean
	@echo Object files removed.

fclean : clean
	@${RM} $(NAME) $(BNAME)
	@make -s -C ./includes/libft/ fclean
	@echo ${NAME} removed.

re : author fclean all
		@echo Rebuild done.

.PHONY: all clean fclean re bonus