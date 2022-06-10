/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:18:55 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 12:18:56 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*res;

	res = malloc(sizeof(t_list) * 1);
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
