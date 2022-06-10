/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:07:15 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 12:34:34 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	int		size;

	if (!s)
		return (NULL);
	if (!len)
		return (ft_calloc(1, 1));
	if (start >= ft_strlen(s))
		return (calloc(1, 1));
	if (len > ft_strlen(s) - start)
		size = ft_strlen(s) - start + 1;
	else
		size = len + 1;
	res = malloc(size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
