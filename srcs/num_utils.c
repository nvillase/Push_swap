/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:25:59 by cparras           #+#    #+#             */
/*   Updated: 2023/06/05 20:13:39 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(int *arr, int arr_len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len)
		{	
			if ((j + 1 < arr_len) && arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_big_num(t_list *lst)
{
	int	bignum;

	bignum = lst->d;
	lst = lst->nt;
	while (lst)
	{
		if (lst->d > bignum)
			bignum = lst->d;
		lst = lst->nt;
	}
	return (bignum);
}

int	find_small_num(t_list *lst_a)
{
	int	smallnum;

	smallnum = lst_a->d;
	lst_a = lst_a->nt;
	while (lst_a)
	{
		if (lst_a->d < smallnum)
			smallnum = lst_a->d;
		lst_a = lst_a->nt;
	}
	return (smallnum);
}

int	find_after_smallnum(t_list *lst_a)
{
	int	smallnum;
	int	aftersmallnum;

	smallnum = find_small_num(lst_a);
	if (lst_a->d == smallnum)
		lst_a = lst_a->nt;
	aftersmallnum = lst_a->d;
	lst_a = lst_a->nt;
	while (lst_a)
	{
		if (lst_a->d < aftersmallnum && lst_a->d != smallnum)
			aftersmallnum = lst_a->d;
		lst_a = lst_a->nt;
	}
	return (aftersmallnum);
}

int	find_big_num_index(t_list *lst, int max)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->d == max)
			return (i);
		lst = lst->nt;
		i++;
	}
	return (-1);
}
