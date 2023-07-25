/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:18:05 by cparras           #+#    #+#             */
/*   Updated: 2023/06/05 18:22:06 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	rslt;
	int		sign;

	i = 0;
	rslt = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	if (!ft_isdigit(str[i]))
		printerr("Error\nNon digit characters.", 1);
	while (ft_isdigit(str[i]) == 1)
		rslt = rslt * 10 + (str[i++] - '0');
	if (rslt * sign < INT_MIN || rslt * sign > INT_MAX)
		return (-1);
	return (sign * rslt);
}
