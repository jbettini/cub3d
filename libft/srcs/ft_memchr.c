/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:00:58 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 12:57:44 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp;

	tmp = s;
	while (n--)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		tmp++;
	}
	return (NULL);
}
