/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresh_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noan <noan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:48:57 by noan              #+#    #+#             */
/*   Updated: 2023/07/25 17:48:58 by noan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fresh_str(char *str)
{
	int		i;
	char	*fresh;

	i = ft_strlen(str) + 1;
	fresh = ft_calloc(sizeof(char), i);
	if (!fresh)
		return (NULL);
	return (fresh);
}
