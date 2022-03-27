/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:06:44 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/09 17:32:13 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_buffer(t_buffer *buf, int c_op, int start)
{
	int	i;

	if (buf == NULL)
	{
		i = 7;
		if (c_op)
			i = 8;
		if (write_hex(i, start))
		{
			write(1, "\n", 1);
			return (0);
		}
	}
	return (1);
}

void	buffer_else(int c_op, int start, t_buffer *buf)
{
	int	i;

	i = 7;
	if (c_op)
		i = 8;
	write_hex(i, start);
	i = 1;
	if (c_op)
		i = 2;
	write(1, "  ", i);
	write_chars_hex(buf->current, c_op, buf->bytes);
	if (c_op)
	{
		write(1, "  ", 2);
		write_chars(buf->current, buf->bytes);
	}
}
