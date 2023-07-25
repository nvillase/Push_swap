/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:38:45 by cparras           #+#    #+#             */
/*   Updated: 2023/06/06 21:01:44 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	is_sorted(t_list *a, t_list *b)
{
	if (b)
		return (1);
	while (a)
	{
		if (a->nt && a->d > a->nt->d)
			return (1);
		a = a->nt;
	}
	return (0);
}

void	washing(t_list **a, t_list **b, int *array)
{
	ft_lstclear(a);
	ft_lstclear(b);
	free(array);
	return ;
}

void	instructs(char *s, t_list **a, t_list **b)
{
	if (!ft_strcmp(s, "sa\n"))
		b_swap(*a);
	else if (!ft_strcmp(s, "sb\n"))
		b_swap(*b);
	else if (!ft_strcmp(s, "ss\n"))
		return (b_swap(*a), b_swap(*b));
	else if (!ft_strcmp(s, "pa\n"))
		b_push(b, a);
	else if (!ft_strcmp(s, "pb\n"))
		b_push(a, b);
	else if (!ft_strcmp(s, "ra\n"))
		b_rotate(a);
	else if (!ft_strcmp(s, "rb\n"))
		b_rotate(b);
	else if (!ft_strcmp(s, "rr\n"))
		return (b_rotate(a), b_rotate(b));
	else if (!ft_strcmp(s, "rra\n"))
		b_reverse_rotate(a);
	else if (!ft_strcmp(s, "rrb\n"))
		b_reverse_rotate(b);
	else if (!ft_strcmp(s, "rrr\n"))
		return (b_reverse_rotate(a), b_reverse_rotate(b));
	else
		return ((void)b_washing(a, b, 2, s), exit(2));
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;
	char	*s;

	b = NULL;
	a = NULL;
	i = 1;
	if (ac < 2)
		printerr("Error\nNumber of parameters must be at least 2.", 1);
	if (ac == 2)
	{
		av = get_av(av[1]);
		i = 0;
	}
	b_checks(av, i, &a);
	s = get_next_line(0);
	while (s)
	{
		instructs(s, &a, &b);
		free(s);
		s = get_next_line(0);
	}
	i = is_sorted(a, b);
	return (b_washing(&a, &b, i, NULL));
}
