NAME = push_swap

SRCS = parsing.c					\
	  main.c						\
	  operations_push_swap.c		\
	  operations_rotate.c			\
	  sorting/sorting.c				\
	  sorting/medium_sorting.c		\

OBJS = $(SRCS:.c=.o)

CC  = gcc

CFLAGS =  -Wall -Wextra -Werror
SAN = -g3 -fsanitize=address
RM  = rm -f

BLACK		:= $(shell tput -Txterm setaf 0)
RED		:= $(shell tput -Txterm setaf 1)
GREEN		:= $(shell tput -Txterm setaf 2)
YELLOW		:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	:= $(shell tput -Txterm setaf 4)
PURPLE		:= $(shell tput -Txterm setaf 5)
BLUE		:= $(shell tput -Txterm setaf 6)
WHITE		:= $(shell tput -Txterm setaf 7)
RESET		:= $(shell tput -Txterm sgr0)

ifneq ("$(wildcard $(/libft/libft.a))","")
LIBFT_EXISTS = 1
else
LIBFT_EXISTS = 0
endif

$(NAME): $(OBJS)
	@echo "$(LIGHTPURPLE)Compilation...$(RESET)"
	if [ LIBFT_EXISTS=0 ]; then make bonus -C libft; fi;
	@echo "$(PURPLE)Libft compiled$(RESET)"
	@(gcc -o $(NAME) -I include $(SRCS) libft/libft.a $(CFLAGS))
	@echo "$(GREEN)Compilation OK$(RESET)"

all:  $(NAME)

clean:
	@echo "$(RED)Deleting objects$(RESET)"
	make clean -C libft
	@($(RM)	$(OBJS))

fclean:  clean
	@echo "$(RED)Deleting executables$(RESET)"
	@($(RM) $(NAME))

re: fclean all

san :
	@(gcc -o $(NAME) -I include $(SRCS) libft/libft.a $(CFLAGS) $(SAN))

.PHONY: all clean fclean re
