NAME = PUSH_SWAP
CC = gcc
CCFLAG = -g -Wall -Wextra -Werror
LIB = ./include/libft/libft.a
RM = rm -f
SRCS =  
OBJS = $(SRCS:.c=.o)
CMD = -L ./include/libft/ -lft

all: $(LIB) $(NAME)

$(LIB):
	make -C ./include/libft/ all

.c.o:
	$(CC) $(CCFLAG) $(CMD) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CCFLAG) $(OBJS) $(CMD) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C ./include/libft/ clean

fclean: clean
	$(RM) $(NAME)

re: fclean all