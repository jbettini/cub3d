/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:58:44 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/17 18:02:22 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_append_char(char *str, char c)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!res)
		return (NULL);
	if (!str)
	{
		res[0] = c;
		res[1] = '\0';
		return (res);
	}
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = c;
	res[++i] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*line;
	int		n;

	line = NULL;
	while ((n = read(fd, &c, 1)) > 0 && c != '\n')
	{
		line = ft_append_char(line, c);
		if (!line)
			return (NULL);
	}
	if (n > 0)
	{
		line = ft_append_char(line, c);
		if (!line)
			return (NULL);
	}
	if (n == -1)
		return (NULL);
	return (line);
}
