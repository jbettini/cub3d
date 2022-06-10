/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:02:26 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 12:35:30 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	if (!(*needle))
		return ((char *)haystack);
	len_needle = ft_strlen(needle);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (!ft_strncmp(&haystack[i], needle, len_needle)
			&& i + len_needle <= len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
