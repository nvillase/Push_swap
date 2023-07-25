/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:17:43 by cparras           #+#    #+#             */
/*   Updated: 2023/06/05 20:12:53 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three(t_list **a)
{
	if (ft_lstsize(*a) == 2)
		swap(*a, 'a');
	else if ((*a)->d > (*a)->nt->d && (*a)->nt->d < (*a)->nt->nt->d
		&& (*a)->d < (*a)->nt->nt->d)
		swap(*a, 'a');
	else if ((*a)->d > (*a)->nt->d && (*a)->nt->d < (*a)->nt->nt->d
		&& (*a)->d > (*a)->nt->nt->d)
		rotate(a, 'a');
	else if ((*a)->d < (*a)->nt->d && (*a)->nt->d > (*a)->nt->nt->d
		&& (*a)->d < (*a)->nt->nt->d)
	{
		swap(*a, 'a');
		rotate(a, 'a');
	}
	else if ((*a)->d > (*a)->nt->d && (*a)->nt->d > (*a)->nt->nt->d
		&& (*a)->d > (*a)->nt->nt->d)
	{
		rotate(a, 'a');
		swap(*a, 'a');
	}
	else if ((*a)->d < (*a)->nt->d && (*a)->nt->d > (*a)->nt->nt->d
		&& (*a)->d > (*a)->nt->nt->d)
		reverse_rotate(a, 'a');
}

void	five(t_list **a, t_list **b)
{
	int	smallnum;
	int	aftersmallnum;

	smallnum = find_small_num(*a);
	if (ft_lstsize(*a) == 5)
		aftersmallnum = find_after_smallnum(*a);
	else
		aftersmallnum = smallnum;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->d == smallnum || (*a)->d == aftersmallnum)
			push(a, b, 'b');
		else
			rotate(a, 'a');
	}
	three(a);
	if ((*b)->nt && (*b)->d < (*b)->nt->d)
		swap(*b, 'b');
	while (*b)
		push(b, a, 'a');
}

void	sort(t_list **a, t_list **b, int *array, t_data *data)
{
	if (ft_lstsize(*a) <= 3)
		three(a);
	else if (ft_lstsize(*a) <= 5)
		five(a, b);
	else
	{
		data->t_num = ft_lstsize(*a);
		data->median = (data->t_num / 2);
		if (data->t_num <= 30)
			data->n = 5;
		else if (data->t_num <= 150)
			data->n = 8;
		else
			data->n = 18;
		data->size = (data->t_num / data->n);
		data->start = data->median - data->size;
		data->end = data->median + data->size;
		from_a_to_b(a, b, array, data);
		from_b_to_a(a, b, array, data);
	}
}

void	washing(t_list **a, t_list **b, int *array)
{
	ft_lstclear(a);
	ft_lstclear(b);
	free(array);
	return ;
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		*array;
	t_data	data;

	a = NULL;
	b = NULL;
	i = 1;
	if (ac < 2)
		printerr("Error\nNumber of parameters must be at least 2.", 1);
	if (ac == 2)
	{
		av = get_av(av[1]);
		i = 0;
	}
	checks(av, i, &a);
	array = sort_array(a);
	sort(&a, &b, array, &data);
	washing(&a, &b, array);
	return (0);
}
