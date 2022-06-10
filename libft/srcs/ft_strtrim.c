/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:04:34 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 12:30:25 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	if (!s1)
		return (NULL);
	if (!*s1 || !set || !*set)
		return (ft_strdup(s1));
	start = 0;
	while (is_in_set(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (is_in_set(set, s1[end]))
		end--;
	res = ft_substr(s1, start, end - start + 1);
	return (res);
}
