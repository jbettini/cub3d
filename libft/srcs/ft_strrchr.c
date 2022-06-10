/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:03:21 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 12:03:22 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	i = ft_strlen(s);
	while (i--)
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	return (NULL);
}
