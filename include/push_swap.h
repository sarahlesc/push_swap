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
int		swap_list(t_double_list **stack);
void	swap_both(t_double_list **stack_a, t_double_list **stack_b);
int		push_list(t_double_list **first_stack, t_double_list **second_stack);
int		rotate_list(t_double_list **stack);
void		rotate_both(t_double_list **stack_a, t_double_list **stack_b);
int		reverse_rotate_list(t_double_list **stack);
void		reverse_rotate_both(t_double_list **stack_a, t_double_list **stack_b);

#endif
