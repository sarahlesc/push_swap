#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/include/libft.h"

typedef struct s_compt
{
	int	value;
}			t_compt;

void	check_list(t_double_list **stack_a);
void	check_duplicates_list(char *str, char **argv, int i,
		t_double_list **stack_a);
void	nb_is_decim(char *str, t_double_list **stack_a, int true_false);
void	print_error(t_double_list **stack_a);
int		swap_list(t_double_list **stack, t_compt *compt);
void	swap_both(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt);
int		push_list(t_double_list **first_stack, t_double_list **second_stack,
		t_compt *compt);
int		rotate_list(t_double_list **stack, t_compt *compt);
void	rotate_both(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt);
int		reverse_rotate_list(t_double_list **stack, t_compt *compt);
void	reverse_rotate_both(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt);
void	call_push_swap(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt);
void	very_small_sorting(t_double_list **stack_a, t_compt *compt);
void	small_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt);
void	medium_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt);
void	large_sorting(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt);
void	stack_is_sorted(t_double_list *stack);
void	move_to_top(int nb, t_double_list **stack, t_compt *compt);
void	sort_stack_b(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt);
int		smallest_number_list(t_double_list **stack);
int		biggest_number_list(t_double_list **stack);
int		find_median(t_double_list *stack);
int		find_quartiles(double q, t_double_list *stack);
void	swap_sort(t_double_list **stack);
void	push_all_to_stack_a(t_double_list **stack_a, t_double_list **stack_b,
	t_compt *compt);
void	sort_with_median(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt);
void	sort_stack_b(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt);
int		smallest_or_biggest(int smallest, int biggest, t_double_list **stack);
void 	move_to_stack_b(int median, t_double_list **stack_a, t_double_list **stack_b, t_compt *compt);

#endif
