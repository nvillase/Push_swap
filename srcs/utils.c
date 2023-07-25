/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:09:21 by cparras           #+#    #+#             */
/*   Updated: 2023/06/05 22:32:57 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**get_av(char *av)
{
	char	**array;

	if (ft_strlen(av) <= 0)
		printerr("Error\nPlease type integers between doubles quotes.", 1);
	array = ft_split(av, ' ');
	if (!array)
		printerr("Error\nPlease type integers between double quotes.", 1);
	if (ft_arraylen(array) == 1)
		printerr("Error\nPlease type at least two numbers.", 1);
	return (array);
}

void	fill_stack(char	**av, int option, t_list **lst)
{
	int		i;

	i = option -1;
	while (av[++i])
		ft_lstadd_back(lst, ft_lstnew(ft_atoi(av[i])));
}

int	*sort_array(t_list *lst)
{
	size_t	i;
	int		*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (ft_lstsize(lst)));
	while (lst)
	{
		arr[i] = lst->d;
		lst = lst->nt;
		i++;
	}
	bubble_sort(arr, i);
	return (arr);
}
