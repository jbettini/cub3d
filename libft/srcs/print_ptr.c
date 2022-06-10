/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:36:17 by ydanset           #+#    #+#             */
/*   Updated: 2021/11/05 18:03:02 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static int	get_len_addr(uintptr_t addr, int precision)
{
	int	len;

	if (!addr && precision == 0)
		return (0);
	if (!addr)
		return (1);
	len = 0;
	while (addr)
	{
		addr /= 16;
		len++;
	}
	return (len);
}

static void	print_addr(uintptr_t addr, int len_addr, int x)
{
	if (x == 1)
	{
		ft_putstr("0x");
		if (!len_addr)
			return ;
	}
	if (addr > 15)
		print_addr(addr / 16, len_addr, 0);
	ft_putchar("0123456789abcdef"[addr % 16]);
}

int	print_ptr(void *ptr, t_opts opts)
{
	int			count_char;
	int			len_addr;
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	len_addr = get_len_addr(addr, opts.precision);
	count_char = len_addr + 2;
	if (opts.flags.minus)
		print_addr(addr, len_addr, 1);
	while (count_char < opts.width)
	{
		ft_putchar(' ');
		count_char++;
	}
	if (!opts.flags.minus)
		print_addr(addr, len_addr, 1);
	return (count_char);
}
