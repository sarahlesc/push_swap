#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/include/libft.h"

void	check_list(t_double_list *stack_a);
void	check_duplicates_list(char *str, char **argv, int i);
int		nb_is_decim(char *str);
void	print_error();

#endif
