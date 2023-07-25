/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:53:00 by cparras           #+#    #+#             */
/*   Updated: 2023/06/05 17:59:09 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	from_a_to_b(t_list **a, t_list **b, int *array, t_data *data)
{
	while (*a)
	{
		if (ft_lstsize(*a) == 1)
			push(a, b, 'b');
		while (ft_lstsize(*b) < data->end - data->start)
		{
			if (!((*a)->d < array[data->end] && (*a)->d >= array[data->start]))
				rotate(a, 'a');
			else
			{
				push(a, b, 'b');
				if ((*b)->d < array[data->median])
					rotate(b, 'b');
			}
		}
		data->start -= data->size;
		if (data->start < 0)
			data->start = 0;
		data->end += data->size;
		if (data->end >= data->t_num)
			data->end = data->t_num - 1;
	}
}

void	from_b_to_a(t_list **a, t_list **b, int *array, t_data *data)
{
	data->unorder_num = 0;
	data->max = ft_lstsize(*b) - 1;
	while (*b)
	{
		if ((*b) && find_big_num(*b) == array[data->max])
			check_cases(a, b, array, data);
		else
			check_case2(a, data);
	}
	while (data->unorder_num != 0)
	{
		reverse_rotate(a, 'a');
		data->unorder_num--;
	}
}

void	check_cases(t_list **a, t_list **b, int *array, t_data *data)
{
	if ((*b)->d == array[data->max])
	{
		push(b, a, 'a');
		data->max--;
		if ((*a)->nt && (*a)->d > (*a)->nt->d)
		{
			swap(*a, 'a');
			data->max--;
		}
	}
	else if ((*b)->d == array[data->max - 1])
		push(b, a, 'a');
	else
		not_max_num(a, b, data);
}

void	check_case2(t_list **a, t_data *data)
{
	if (data->unorder_num > 0)
	{
		reverse_rotate(a, 'a');
		data->unorder_num--;
		data->max--;
	}
}

void	not_max_num(t_list **a, t_list **b, t_data *data)
{
	if (data->unorder_num == 0 || (*b)->d > ft_lstlast(*a)->d)
	{
		push(b, a, 'a');
		rotate(a, 'a');
		data->unorder_num++;
	}
	else
	{
		if (find_big_num_index(*b, find_big_num(*b)) < ft_lstsize(*b) / 2)
			rotate(b, 'b');
		else
			reverse_rotate(b, 'b');
	}
}
