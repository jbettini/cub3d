/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:34:36 by ydanset           #+#    #+#             */
/*   Updated: 2021/11/05 20:36:28 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	print_var(const char **format, va_list *ap)
{
	t_opts	opts;

	opts = get_opts(format, ap);
	if (**format == 'c')
		return (print_char(va_arg(*ap, int), opts));
	else if (**format == 's')
		return (print_str(va_arg(*ap, char *), opts));
	else if (**format == 'p')
		return (print_ptr(va_arg(*ap, void *), opts));
	else if (**format == 'd' || **format == 'i')
		return (print_int(va_arg(*ap, int), opts));
	else if (**format == 'u')
		return (print_uint(va_arg(*ap, unsigned int), opts));
	else if (**format == 'x')
		return (print_hexa(va_arg(*ap, unsigned int), opts, 0));
	else if (**format == 'X')
		return (print_hexa(va_arg(*ap, unsigned int), opts, 1));
	else if (**format == '%')
		return (print_percentage(opts));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count_char;

	count_char = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count_char += print_var(&format, &ap);
		}
		else
		{
			ft_putchar(*format);
			count_char++;
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (count_char);
}
