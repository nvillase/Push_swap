/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:06:18 by cparras           #+#    #+#             */
/*   Updated: 2023/06/06 20:55:15 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/libft/libft.h"

# define ERR_FORMAT "Only integers are allowed."
# define ERR_PARAMS "The number of parameters must be more than one."

typedef struct s_data
{
	int	median;
	int	size;
	int	start;
	int	end;
	int	n;
	int	t_num;
	int	unorder_num;
	int	max;
}		t_data;

char	**get_av(char *av);
void	checks(char **av, int i, t_list **a);
void	check_format(char **a, int option);
void	check_limits(char **av, int option);
void	fill_stack(char	**av, int option, t_list **lst);
void	check_doubles(t_list **lst);
void	bubble_sort(int *arr, int arr_len);
int		find_big_num(t_list *lst);
int		find_small_num(t_list *lst_a);
int		find_after_smallnum(t_list *lst_a);
int		find_big_num_index(t_list *lst, int max);
int		*sort_array(t_list *lst);
void	swap(t_list *lst, char s);
void	push(t_list **src, t_list **dest, char s);
void	rotate(t_list **lst, char s);
void	reverse_rotate(t_list **lst, char s);
void	three(t_list **a);
void	from_a_to_b(t_list **a, t_list **b, int *array, t_data *data);
void	from_b_to_a(t_list **a, t_list **b, int *array, t_data *data);
void	check_cases(t_list **a, t_list **b, int *array, t_data *data);
void	check_case2(t_list **a, t_data *data);
void	not_max_num(t_list **a, t_list **b, t_data *data);
void	washing(t_list **a, t_list **b, int *array);
void	b_swap(t_list *lst);
void	b_push(t_list **src, t_list **dest);
void	b_rotate(t_list **lst);
void	b_reverse_rotate(t_list **lst);
int		is_sorted(t_list *a, t_list *b);
int		b_washing(t_list **a, t_list **b, int i, char *s);
void	b_checks(char **av, int option, t_list **a);

#endif