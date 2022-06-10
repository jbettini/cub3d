/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:56:41 by ydanset           #+#    #+#             */
/*   Updated: 2021/11/05 20:34:22 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	print_str(char *str, t_opts opts)
{
	int		count_char;
	char	*tmp;

	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (opts.precision != -1)
	{
		tmp = str;
		str = ft_substr(str, 0, opts.precision);
		free(tmp);
	}
	count_char = ft_strlen(str);
	if (opts.flags.minus)
		ft_putstr(str);
	while (count_char < opts.width)
	{
		ft_putchar(' ');
		count_char++;
	}
	if (!opts.flags.minus)
		ft_putstr(str);
	free(str);
	return (count_char);
}
