# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slescure <slescure@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 13:51:58 by slescure          #+#    #+#              #
#    Updated: 2021/06/02 14:35:29 by slescure         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c					\
	  parsing/parsing.c						\
	  operations/operations_push_swap.c		\
	  operations/operations_rotate.c			\
	  operations/operations_reverse_rotate.c			\
	  sorting/sorting_management.c				\
	  sorting/utils_to_sort.c				\
	  sorting/calculation.c				\
	  sorting/small_sorting.c				\
	  sorting/medium_sorting.c		\
	  sorting/big_sorting.c			\

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
	make fclean -C libft
	@($(RM) $(NAME))

re: fclean all

san :
	@(gcc -o $(NAME) -I include $(SRCS) libft/libft.a $(CFLAGS) $(SAN))

.PHONY: all clean fclean re
