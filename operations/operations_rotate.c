#include "../include/push_swap.h"

int	rotate_list_stack_a(t_double_list **stack_a, t_compt *compt)
{
	t_double_list	*temp1;
	t_double_list	*temp2;
	int				store;

	if (ft_double_lstsize(*stack_a) == 0 || ft_double_lstsize(*stack_a) == 1)
		return (-1);
	temp1 = *stack_a;
	temp2 = ft_double_lstcopy(temp1);
	store = temp1->content;
	temp1 = ft_double_lstlast(*stack_a);
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
	printf("ra\n");
	return (0);
}

int	rotate_list_stack_b(t_double_list **stack_b, t_compt *compt)
{
	t_double_list	*temp1;
	t_double_list	*temp2;
	int				store;

	if (ft_double_lstsize(*stack_b) == 0 || ft_double_lstsize(*stack_b) == 1)
		return (-1);
	temp1 = *stack_b;
	temp2 = ft_double_lstcopy(temp1);
	store = temp1->content;
	temp1 = ft_double_lstlast(*stack_b);
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
	printf("rb\n");
	return (0);
}

void	rotate_both(t_double_list **stack_a, t_double_list **stack_b,
		t_compt *compt)
{
	rotate_list_stack_a(stack_a, compt);
	rotate_list_stack_b(stack_b, compt);
	compt->value--;
	printf("rr\n");
}
