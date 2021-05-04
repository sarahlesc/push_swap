#include "push_swap.h"

void 	initialize_tab(t_tab *tab)
{
	tab->size_a = 0;
	tab->size_b = 0;
}

int		swap_a(t_tab *tab)
{
	int		i;
	char	**result;

	i = 2;
	if (tab->size_a == 0 || tab->size_a == 1)
		return (0);
	if (!(result = malloc(sizeof(char **) * tab->size_a)))
		return (-1);
	result[0][0] = tab->a[1][0];
	result[1][0] = tab->a[0][0];
	while (tab->a[i] != '\0')
	{
		result[i][0] = tab->a[i][0];
		i++;
	}
	i = -1;
	while (++i < tab->size_a)
		free (tab->a[i]);
	tab->a = result;
	return (0);
}

int		swap_b(t_tab *tab)
{
	int		i;
	char	**result;

	i = 2;
	if (tab->size_b == 0 || tab->size_b == 1)
		return (0);
	if (!(result = malloc(sizeof(char *) * ft_strlen(tab->b))))
		return (-1);
	result[0][0] = tab->b[1][0];
	result[1][0] = tab->b[0][0];
	while (tab->b[i] != '\0')
	{
		result[i][0] = tab->b[i][0];
		i++;
	}
	while (++i < tab->size_b)
		free (tab->b[i]);
	tab->b = result;
	return (0);
}

void	swap_both(t_tab *tab)
{
	swap_a(tab);
	swap_b(tab);
}

int		push_a(t_tab *tab)
{
	if (tab->size_b == 0)
		return (0);
	tab->a[0][0] = tab->b[0][0];
}

int		push_b(t_tab *tab)
{
	if (tab->size_a == 0)
		return (0);
	tab->b[0][0] = tab->a[0][0];
}

int		rotate_a(t_tab *tab)
{
	int i;
	char c;

	i = tab->size_a;
	if (tab->size_a == 0)
		return (0);
	c = tab->a[0][0];
	while (i > 0)
	{
		tab->a[i - 1][0] = tab->a[i][0];
		i--;
	}
	tab->a[tab->size_a][0] = c;
	return (0);
}

int		rotate_b(t_tab *tab)
{
	int i;
	char c;

	i = tab->size_b;
	if (tab->size_b == 0)
		return (0);
	c = tab->b[0][0];
	while (i > 0)
	{
		tab->b[i - 1][0] = tab->b[i][0];
		i--;
	}
	tab->b[tab->size_b][0] = c;
	return (0);
}

int		rotate_both(t_tab *tab)
{
	rotate_a(tab);
	rotate_b(tab);
}

int		reverse_rotate_a(t_tab *tab)
{
	int i;
	char c;

	i = 0;
	if (tab->size_a == 0 || tab->size_a == 1)
		return (0);
	c = tab->a[tab->size_a][0];
	while (i < tab->size_a)
	{
		tab->a[i + 1][0] = tab->a[i][0];
		i++;
	}
	tab->a[0][0] = c;
	return (0);
}

int		reverse_rotate_b(t_tab *tab)
{
	int i;
	char c;

	i = 0;
	if (tab->size_b == 0 || tab->size_b == 1)
		return (0);
	c = tab->b[tab->size_b][0];
	while (i < tab->size_b)
	{
		tab->b[i + 1][0] = tab->b[i][0];
		i++;
	}
	tab->b[0][0] = c;
	return (0);
}


void	reverse_rotate_both(t_tab *tab)
{
	reverse_rotate_a(tab);
	reverse_rotate_b(tab);
}
