/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:53:00 by ydanset           #+#    #+#             */
/*   Updated: 2021/11/05 19:39:18 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	get_len_nbr(int nbr, int precision)
{
	int	len;

	if (!nbr && precision == 0)
		return (0);
	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void	print_nbr_prefix(int nbr, t_opts opts)
{
	if (nbr < 0)
		ft_putchar('-');
	else if (opts.flags.plus)
		ft_putchar('+');
	else if (opts.flags.blank)
		ft_putchar(' ');
}

void	ft_putnbr(int nbr, t_opts opts, int len_nbr, int first_entry)
{
	if (first_entry)
	{
		if (!opts.flags.zero)
			print_nbr_prefix(nbr, opts);
		if (opts.precision == 0 && !nbr)
			return ;
		while (opts.precision-- > len_nbr)
			ft_putchar('0');
	}
	if (nbr == -2147483648)
		ft_putstr("2147483648");
	else if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	else if (nbr < 0)
		ft_putnbr(-nbr, opts, len_nbr, 0);
	else
	{
		ft_putnbr(nbr / 10, opts, len_nbr, 0);
		ft_putnbr(nbr % 10, opts, len_nbr, 0);
	}
}

int	print_int(int nbr, t_opts opts)
{
	int	len_nbr;
	int	count_char;

	len_nbr = get_len_nbr(nbr, opts.precision);
	if (opts.precision > len_nbr)
		count_char = opts.precision;
	else
		count_char = len_nbr;
	if (nbr < 0 || opts.flags.plus || opts.flags.blank)
		count_char++;
	if (opts.flags.zero)
		print_nbr_prefix(nbr, opts);
	if (opts.flags.minus)
		ft_putnbr(nbr, opts, len_nbr, 1);
	while (count_char < opts.width)
	{
		if (opts.flags.zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count_char++;
	}
	if (!opts.flags.minus)
		ft_putnbr(nbr, opts, len_nbr, 1);
	return (count_char);
}
