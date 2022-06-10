/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:02:50 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 12:58:59 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*free_me;

	tmp = *lst;
	while (tmp)
	{
		(*del)(tmp->content);
		free_me = tmp;
		tmp = tmp->next;
		free(free_me);
	}
	*lst = NULL;
}
