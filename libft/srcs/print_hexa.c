/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:58:06 by ydanset           #+#    #+#             */
/*   Updated: 2021/11/05 20:04:01 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static void	i_wish_i_was_a_ternary(int maj, int nbr, int x)
{
	if (x)
	{
		if (maj)
			ft_putchar("0123456789ABCDEF"[nbr]);
		else
			ft_putchar("0123456789abcdef"[nbr]);
	}
	else
	{
		if (maj)
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
}

static int	get_len_uint_hexa(unsigned int nbr, int precision)
{
	int	len;

	if (!nbr && precision == 0)
		return (0);
	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

void	handle_width(unsigned int nbr, t_opts opts, int len_nbr)
{
	int	x;

	if (opts.flags.hashtag && nbr)
		x = 2;
	else
		x = 0;
	while (opts.width-- > len_nbr + x)
		ft_putchar('0');
}

void	ft_putuint_hexa(unsigned int nbr, t_opts opts, int first_entry, int maj)
{
	int	len_nbr;

	if (first_entry)
	{
		if (nbr == 0 && opts.precision == 0)
			return ;
		if (opts.flags.hashtag && nbr)
			i_wish_i_was_a_ternary(maj, 0, 0);
		len_nbr = get_len_uint_hexa(nbr, opts.precision);
		while (opts.precision-- > len_nbr)
			ft_putchar('0');
		if (opts.flags.zero)
			handle_width(nbr, opts, len_nbr);
	}
	if (nbr >= 0 && nbr <= 15)
		i_wish_i_was_a_ternary(maj, nbr, 1);
	else
	{
		ft_putuint_hexa(nbr / 16, opts, 0, maj);
		ft_putuint_hexa(nbr % 16, opts, 0, maj);
	}
}

int	print_hexa(unsigned int nbr, t_opts opts, int maj)
{
	int	count_char;
	int	len_nbr;

	len_nbr = get_len_uint_hexa(nbr, opts.precision);
	if (opts.precision > len_nbr)
		count_char = opts.precision;
	else
		count_char = len_nbr;
	if (opts.flags.hashtag && nbr)
		count_char += 2;
	if (opts.flags.minus)
		ft_putuint_hexa(nbr, opts, 1, maj);
	while (count_char < opts.width)
	{
		if (!opts.flags.zero)
			ft_putchar(' ');
		count_char++;
	}
	if (!opts.flags.minus)
		ft_putuint_hexa(nbr, opts, 1, maj);
	return (count_char);
}
