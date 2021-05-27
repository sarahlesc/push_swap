#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/include/libft.h"

typedef struct s_compt
{
	int	value;
	int	chunk_one;
	int	chunk_two;
	int	chunk_three;
	int	chunk_four;
	int	chunk_five;
	int	chunk_six;
	int	chunk_seven;
	int	chunk_eight;

}			t_compt;

/*
** Parsing
*/

void	check_list(t_double_list **stack_a);
void	check_duplicates_list(char *str, char **argv, int i,
			t_double_list **stack_a);
void	nb_is_decim(char *str, t_double_list **stack_a, int true_false);
void	print_error(t_double_list **stack_a);


/*
** Operations
*/

int		swap_list_stack_a(t_double_list **stack_a, t_compt *compt);
int		swap_list_stack_b(t_double_list **stack_b, t_compt *compt);
void	swap_both(t_double_list **stack_a, t_double_list **stack_b,
			t_compt *compt);
int		push_list_to_stack_a(t_double_list **stack_a,
			t_double_list **stack_b, t_compt *compt);
int		push_list_to_stack_b(t_double_list **stack_b,
			t_double_list **stack_a, t_compt *compt);
int		rotate_list_stack_a(t_double_list **stack_a, t_compt *compt);
int		rotate_list_stack_b(t_double_list **stack_b, t_compt *compt);
void	rotate_both(t_double_list **stack_a, t_double_list **stack_b,
			t_compt *compt);
int		reverse_rotate_list_stack_a(t_double_list **stack_a, t_compt *compt);
int		reverse_rotate_list_stack_b(t_double_list **stack_b, t_compt *compt);
void	reverse_rotate_both(t_double_list **stack_a, t_double_list **stack_b,
			t_compt *compt);
void	push_swap_stacks(t_double_list **stack_a, t_compt *compt);
void	call_push_swap(t_double_list **stack_a, t_double_list **stack_b,
			t_compt *compt);
void	very_small_sorting(t_double_list **stack_a, t_compt *compt);
void	small_sorting(t_double_list **stack_a, t_double_list **stack_b,
			t_compt *compt);
void	medium_sorting(t_double_list **stack_a, t_double_list **stack_b,
			t_compt *compt);
void	large_sorting(t_double_list **stack_a, t_double_list **stack_b,
			t_compt *compt);
int		stack_is_sorted(t_double_list *stack);
void	move_to_top(int nb, t_double_list **stack, t_compt *compt, int pos);
void	sort_stack_b(t_double_list **stack_a, t_double_list **stack_b,
			t_compt *compt);
int		smallest_number_list(t_double_list **stack);
int		biggest_number_list(t_double_list **stack);
int		divide_stack_by_three(double q, t_double_list *stack);
int		divide_stack_by_eight(double q, t_double_list *stack);
void	swap_sort(t_double_list **stack);
void	sort_with_median(t_double_list **stack_a, t_double_list **stack_b,
			t_compt *compt);
void	sort_stack_b(t_double_list **stack_a, t_double_list **stack_b,
			t_compt *compt);
int		smallest_to_use(int smallest, int biggest, t_double_list **stack);
int		get_minimum(int pivot, t_double_list **stack_a, t_compt *compt);
int		compare_nb_operations(int i, int j, t_double_list **temp);
void	move_stack_medium(int pivot, t_double_list **stack_a,
			t_double_list **stack_b, t_compt *compt);
void	move_stack_large(int pivot, t_double_list **stack_a,
			t_double_list **stack_b, t_compt *compt);
#endif
