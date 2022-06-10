/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:35:01 by ydanset           #+#    #+#             */
/*   Updated: 2021/11/05 16:27:59 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	print_char(int c, t_opts opts)
{
	int	count_char;

	count_char = 0;
	if (opts.flags.minus)
		ft_putchar(c);
	while (++count_char < opts.width)
		ft_putchar(' ');
	if (!opts.flags.minus)
		ft_putchar(c);
	return (count_char);
}
