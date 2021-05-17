#include "../include/push_swap.h"

void 	call_push_swap(t_double_list **stack_a, t_double_list **stack_b)
{
	if (ft_double_lstsize(*stack_a) <= 10)
		small_sorting(stack_a, stack_b);
	//if (ft_double_lstsize(*stack_a) > 10 && ft_double_lstsize(*stack_a) <= 100)
	//	medium_sorting(stack_a, stack_b);
	//if (ft_double_lstsize(*stack_a) > 100 && ft_double_lstsize(*stack_a) <= 500)
	//	large_sorting(stack_a, stack_b);
	else
		print_error();
}

void 	very_small_sorting(t_double_list **stack_a)
{
	t_double_list	*temp;
	t_double_list	*temp2;

	temp = ft_double_lstfirst(*stack_a);
	if (temp->content > temp->next->content)
		swap_list(stack_a);
	temp = ft_double_lstlast(*stack_a);
	if (temp->content < temp->previous->content)
		reverse_rotate_list(stack_a);
	temp2 = ft_double_lstfirst(*stack_a);
	if (temp2->content > temp->content)
		reverse_rotate_list(stack_a);
}

void 	small_sorting(t_double_list **stack_a, t_double_list **stack_b)
{
	t_double_list *temp;

	if (ft_double_lstsize(*stack_a) < 4)
		very_small_sorting(stack_a);
	if (ft_double_lstsize(*stack_a) > 3 && ft_double_lstsize(*stack_a) < 6)
	{
		while (ft_double_lstsize(*stack_a) != 3)
			push_list(stack_b, stack_a);
		very_small_sorting(stack_a);
		if (ft_double_lstsize(*stack_b) > 1)
		{
			temp = ft_double_lstfirst(*stack_b);
			if (temp->content > temp->next->content)
				swap_list(stack_b);
			printf("\n");
			ft_double_print_list(*stack_b);
			printf("\n");
		}
		while (ft_double_lstsize(*stack_b) >= 1)
		{
			printf("\n");
			ft_double_print_list(*stack_b);
			printf("\n");
			push_list(stack_a, stack_b);
		}
	}
}

/*void 	medium_sorting(t_double_list **stack_a, t_double_list **stack_b)
{

}*/

void	stack_is_sorted(t_double_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content >= stack->next->content)
		{
			printf("KO\n"); // faire une fonction pour bien sortir en free tout ?
			exit (0);
		}
		stack = stack->next;
	}
	printf("OK");
}

void 	move_to_top(int nb, t_double_list **stack_a)
{
	int				i;
	t_double_list	*temp;
	t_double_list	*temp2;

	i = 0;
	temp = ft_double_lstfirst(*stack_a);
	while (nb != temp->content)
	{
		i++;
		temp = temp->next;
	}
	temp = ft_double_lstfirst(*stack_a);
	temp2 = ft_double_lstfirst(*stack_a);
	if (nb < ft_double_lstsize(*stack_a) / 2)
	{
		while (temp2->content != nb)
		{
			rotate_list(stack_a);
			temp = temp->next;
		}
	}
	else
	{
		while (temp2->content != nb)
		{
			reverse_rotate_list(stack_a);
			temp = temp->next;
		}
	}
}

/*void 	smallest_number_list(t_double_list **stack_a)
{
	t_double_list *temp;
	t_double_list *temp2;
	temp = ft_double_lstfirst(*stack_a);
	while (temp->next != NULL)
	{
		
	}
}*/
