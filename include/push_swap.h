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
void 	call_push_swap(t_double_list **stack_a, t_double_list **stack_b);
void 	very_small_sorting(t_double_list **stack_a);
void 	small_sorting(t_double_list **stack_a, t_double_list **stack_b);
void 	medium_sorting(t_double_list **stack_a, t_double_list **stack_b);
void 	large_sorting(t_double_list **stack_a, t_double_list **stack_b);
void	stack_is_sorted(t_double_list *stack);
void 	move_to_top(int nb, t_double_list **stack_a);
int 	smallest_number_list(t_double_list **stack_a);

#endif
