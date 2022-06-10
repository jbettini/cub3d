/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:20:20 by ydanset           #+#    #+#             */
/*   Updated: 2022/05/13 04:52:41 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	res;

	if (!s)
		return (0);
	res = 0;
	while (*(s++))
		res++;
	return (res);
}

size_t	ft_strslen(char **s)
{
	size_t	res;

	if (!s)
		return (0);
	res = 0;
	while (*(s++))
		res++;
	return (res);
}