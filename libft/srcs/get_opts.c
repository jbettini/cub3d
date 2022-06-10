/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:35:47 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/11 11:14:18 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

void	get_width(const char **format, t_opts *opts, va_list *ap)
{
	if (**format == '*')
	{
		opts->width = va_arg(*ap, int);
		(*format)++;
		if (opts->width < 0)
			opts->width *= -1;
		return ;
	}
	if (!ft_isdigit(**format))
		return ;
	opts->width = 0;
	while (**format && ft_isdigit(**format))
	{
		opts->width = opts->width * 10 + (**format - 48);
		(*format)++;
	}
}

void	get_precision(const char **format, t_opts *opts, va_list *ap)
{
	if (**format != '.')
		return ;
	(*format)++;
	if (**format == '*')
	{
		opts->precision = va_arg(*ap, int);
		if (opts->precision < 0)
			opts->precision = -1;
		(*format)++;
		return ;
	}
	if (**format == '-')
		(*format)++;
	opts->precision = 0;
	while (**format && ft_isdigit(**format))
	{
		opts->precision = opts->precision * 10 + (**format - 48);
		(*format)++;
	}
}

void	get_flags(const char **format, t_opts *opts)
{
	while (**format && is_flag(**format))
	{
		if (**format == ' ')
			opts->flags.blank = 1;
		else if (**format == '-')
			opts->flags.minus = 1;
		else if (**format == '+')
			opts->flags.plus = 1;
		else if (**format == '0')
			opts->flags.zero = 1;
		else
			opts->flags.hashtag = 1;
		(*format)++;
	}
}

t_opts	inst_opts(void)
{
	t_opts	opts;

	opts.width = -1;
	opts.precision = -1;
	opts.flags.minus = 0;
	opts.flags.plus = 0;
	opts.flags.zero = 0;
	opts.flags.blank = 0;
	opts.flags.hashtag = 0;
	return (opts);
}

t_opts	get_opts(const char **format, va_list *ap)
{
	t_opts	opts;

	opts = inst_opts();
	get_flags(format, &opts);
	get_width(format, &opts, ap);
	get_precision(format, &opts, ap);
	if (opts.precision != -1 || opts.flags.minus)
		opts.flags.zero = 0;
	if (opts.flags.plus)
		opts.flags.blank = 0;
	return (opts);
}
