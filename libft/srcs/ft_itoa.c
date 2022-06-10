/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:20:29 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 12:59:31 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len_res(int n)
{
	int	res;

	if (!n)
		return (1);
	res = 0;
	if (n < 0)
		res++;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len_res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_res = get_len_res(n);
	res = malloc(get_len_res(n) + 1);
	if (!res)
		return (NULL);
	if (!n)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[len_res] = '\0';
	while (n)
	{
		res[--len_res] = (n % 10) + 48;
		n /= 10;
	}
	return (res);
}
