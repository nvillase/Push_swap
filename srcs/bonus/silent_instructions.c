/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:17:31 by cparras           #+#    #+#             */
/*   Updated: 2023/06/05 22:09:19 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	b_swap(t_list *stack)
{
	int	temp;

	if (!stack || !stack->nt)
		return ;
	temp = stack->d;
	stack->d = stack->nt->d;
	stack->nt->d = temp;
}

void	b_push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->nt;
	temp->nt = NULL;
	ft_lstadd_front(dest, temp);
}

void	b_rotate(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->nt)
		return ;
	temp = *stack;
	*stack = (*stack)->nt;
	temp->nt = NULL;
	ft_lstadd_back(stack, temp);
}

void	b_reverse_rotate(t_list **stack)
{	
	t_list	*temp;

	if (!*stack || !(*stack)->nt)
		return ;
	temp = *stack;
	while (temp->nt->nt)
		temp = temp->nt;
	temp->nt->nt = *stack;
	*stack = temp->nt;
	temp->nt = NULL;
}

int	b_washing(t_list **a, t_list **b, int i, char *s)
{
	if (i == 0)
		ft_printf("OK\n");
	else if (i == 2)
		ft_printf("Error\n");
	else
		ft_printf("KO\n");
	if (s)
		free(s);
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}
