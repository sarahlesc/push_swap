#include "include/push_swap.h"

int	rotate_list(t_double_list **stack, t_compt *compt)
{
	t_double_list	*temp1;
	t_double_list	*temp2;
	int		store;

	if (ft_double_lstsize(*stack) == 0 || ft_double_lstsize(*stack) == 1)
		return (-1);
	temp1 = *stack;
	temp2 = ft_double_lstcopy(temp1);
	store = temp1->content;
	temp1 = ft_double_lstlast(*stack);
	temp1->content = store;
	temp1 = temp1->previous;
	temp2 = ft_double_lstlast(temp2);
	while (temp2->previous != NULL)
	{
		temp1->content = temp2->content;
		temp1 = temp1->previous;
		temp2 = temp2->previous;
	}
	compt->value++;
	ft_double_lstclear(&temp2, 0);
	return (0);
}

void	rotate_both(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	rotate_list(stack_a, compt);
	rotate_list(stack_b, compt);
	compt->value--;
	printf("rr\n");
}

int	reverse_rotate_list(t_double_list **stack, t_compt *compt)
{
	t_double_list	*temp1;
	t_double_list	*temp2;
	int		store;

	if (ft_double_lstsize(*stack) == 0 || ft_double_lstsize(*stack) == 1)
		return (-1);
	temp1 = ft_double_lstlast(*stack);
	temp2 = ft_double_lstcopy(*stack);
	store = temp1->content;
	temp1 = ft_double_lstfirst(*stack);
	temp1->content = store;
	temp1 = temp1->next;
	while (temp2->next != NULL)
	{
		temp1->content = temp2->content;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	compt->value++;
	ft_double_lstclear(&temp2, 0);
	return (0);
}

void	reverse_rotate_both(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	reverse_rotate_list(stack_a, compt);
	reverse_rotate_list(stack_b, compt);
	printf("rrr\n");
	compt->value--;
}
