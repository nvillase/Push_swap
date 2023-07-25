/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:05:59 by cparras           #+#    #+#             */
/*   Updated: 2023/06/06 21:00:39 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	checks(char **av, int option, t_list **a)
{
	t_list	*tmp;

	tmp = NULL;
	check_format(av, option);
	check_limits(av, option);
	fill_stack(av, option, a);
	if (!option)
		free_array(av);
	check_doubles(a);
	tmp = *a;
	while (tmp->nt)
	{
		if (tmp->d > tmp->nt->d)
			return ;
		tmp = tmp->nt;
	}
	ft_lstclear(a);
	exit (2);
}

void	check_format(char **a, int option)
{
	int	i;
	int	j;

	i = option - 1;
	while (a[++i])
	{
		j = 1;
		while (a[i][j])
		{
			if ((!ft_isdigit(a[i][0]) && a[i][0] != '-')
			|| !ft_isdigit(a[i][j]))
			{
				ft_printf("Error\nOnly integers are allowed.\n");
				if (!option)
					free_array(a);
				exit (2);
			}
			j++;
		}
	}
}

void	check_limits(char **av, int option)
{
	int	nb;
	int	i;

	i = option - 1;
	nb = 0;
	while (av[++i])
	{
		nb = ft_atoi(av[i]);
		if (nb == -1 && ft_strncmp("-1", av[i], ft_strlen(av[i])))
		{
			if (!option)
			{
				i += 1;
				free_array(av);
			}
			ft_printf("Error\nParameter n.%d is out of int limits.\n", i);
			exit (2);
		}
	}
}

void	check_doubles(t_list **lst)
{
	t_list	*tmp;
	t_list	*current;
	t_list	*iter;

	tmp = *lst;
	while (tmp)
	{
		current = tmp;
		iter = tmp->nt;
		while (iter)
		{
			if (current->d == iter->d)
			{
				ft_lstclear(lst);
				printerr("Error\nDoubles are not allowed.", 1);
			}
			iter = iter->nt;
		}
		tmp = tmp->nt;
	}
}

void	b_checks(char **av, int option, t_list **a)
{
	check_format(av, option);
	check_limits(av, option);
	fill_stack(av, option, a);
	if (!option)
		free_array(av);
	check_doubles(a);
}
