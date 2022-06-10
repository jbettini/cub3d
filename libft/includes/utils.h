/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:02:20 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/09 09:54:14 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdarg.h>
# include <string.h>

typedef struct s_flags
{
	int	minus;
	int	plus;
	int	zero;
	int	blank;
	int	hashtag;
}				t_flags;

typedef struct s_opts
{
	int		width;
	int		precision;
	t_flags	flags;
}				t_opts;

t_opts	get_opts(const char **format, va_list *ap);
int		is_flag(char c);
int		print_char(int c, t_opts opts);
int		print_str(char *str, t_opts opts);
int		print_ptr(void *ptr, t_opts opts);
int		print_int(int x, t_opts opts);
int		print_percentage(t_opts opts);
int		print_uint(unsigned int x, t_opts opts);
int		print_hexa(unsigned int nbr, t_opts opts, int maj);

#endif
