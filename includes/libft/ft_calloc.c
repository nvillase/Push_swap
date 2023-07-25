/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noan <noan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:49:46 by noan              #+#    #+#             */
/*   Updated: 2023/07/25 17:49:48 by noan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	char	*array;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	len = (size_t)(nmemb * size);
	if (len / nmemb != size || len / size != nmemb)
		return (NULL);
	array = malloc(len);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, len);
	return (array);
}
