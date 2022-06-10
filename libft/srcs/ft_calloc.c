/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:02:37 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 13:03:54 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count * size)
		res[i++] = '\0';
	return ((void *)res);
}
