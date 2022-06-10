/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:02:15 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 13:18:36 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	i_was_not_supposed_to_be_here(int *i, char const *s, char c)
{
	int	j;

	while (s[*i] && s[*i] == c)
		(*i)++;
	j = 0;
	while (s[*i + j] && s[*i + j] != c)
		j++;
	return (j);
}

static char	**free_on_error(char **res, int n)
{
	while (n--)
		free(res[n]);
	free(res);
	return (NULL);
}

static char	**malloc_res(char const *s, char c)
{
	int		nb_word;
	int		i;
	char	**res;

	if (!s)
		return (NULL);
	nb_word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nb_word++;
		while (s[i] && s[i] != c)
			i++;
	}
	res = malloc(sizeof(char *) * (nb_word + 1));
	if (!res)
		return (NULL);
	res[nb_word] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	res = malloc_res(s, c);
	if (!res)
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		j = i_was_not_supposed_to_be_here(&i, s, c);
		if (j > 0)
		{
			res[k++] = ft_substr(s, i, j);
			if (!res[k - 1])
				return (free_on_error(res, k - 1));
		}
		i = i + j;
	}
	return (res);
}
