/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:03:00 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 12:03:02 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp_dst;
	const char	*tmp_src;

	if (!dst && !src)
		return (NULL);
	tmp_dst = dst;
	tmp_src = src;
	while (n--)
		*(tmp_dst++) = *(tmp_src++);
	return (dst);
}
