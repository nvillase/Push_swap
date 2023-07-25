/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:40:54 by cparras           #+#    #+#             */
/*   Updated: 2023/06/05 16:13:02 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list *stack, char s)
{
	int	temp;

	if (!stack || !stack->nt)
		return ;
	temp = stack->d;
	stack->d = stack->nt->d;
	stack->nt->d = temp;
	ft_printf("s%c\n", s);
}

void	push(t_list **src, t_list **dest, char s)
{
	t_list	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->nt;
	temp->nt = NULL;
	ft_lstadd_front(dest, temp);
	ft_printf("p%c\n", s);
}

void	rotate(t_list **stack, char s)
{
	t_list	*temp;

	if (!*stack || !(*stack)->nt)
		return ;
	temp = *stack;
	*stack = (*stack)->nt;
	temp->nt = NULL;
	ft_lstadd_back(stack, temp);
	ft_printf("r%c\n", s);
}

void	reverse_rotate(t_list **stack, char s)
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
	ft_printf("rr%c\n", s);
}
