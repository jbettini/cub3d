/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:02:06 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 12:57:26 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;

	if (!n)
		return (0);
	tmp_s1 = s1;
	tmp_s2 = s2;
	while (n-- > 1 && (*tmp_s1 == *tmp_s2))
	{
		tmp_s1++;
		tmp_s2++;
	}
	return (*tmp_s1 - *tmp_s2);
}
