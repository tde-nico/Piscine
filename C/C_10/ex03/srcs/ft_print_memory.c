/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:49:54 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/15 08:32:43 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	write_hex(int size, int nbr)
{
	char	*str;
	int		i;

	str = malloc(sizeof(*str) * size + 1);
	i = 0;
	while (i < size)
		str[i++] = '0';
	i = size - 1;
	while (nbr > 0)
	{
		if (nbr % 16 > 9)
			str[i] = 'a' - 10 + (nbr % 16);
		else
			str[i] = '0' + (nbr % 16);
		nbr /= 16;
		i--;
	}
	write(1, str, size);
	free(str);
	return (1);
}

int	write_chars(char *buffer, int bytes)
{
	int	i;

	i = 0;
	write(1, "|", 1);
	while (i < bytes)
	{
		if (buffer[i] < ' ' || buffer[i] > 127)
			write(1, ".", 1);
		else
			write(1, &buffer[i], 1);
		i++;
	}
	write(1, "|", 1);
	return (1);
}

int	write_chars_hex(char *buffer, int c_op, int bytes)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i >= bytes)
			write(1, "  ", 2);
		else
			write_hex(2, buffer[i]);
		if (i < 15)
		{
			if (c_op && i == 7)
				write(1, "  ", 2);
			else
				write(1, " ", 1);
		}
		i++;
	}
	return (1);
}

void	clean_buffer(t_buffer *buffer)
{
	int	i;

	i = buffer->bytes;
	while (i < 16)
	{
		buffer->current[i] = '\0';
		i++;
	}
}

void	ft_display_buffer(t_buffer *buf, int c_op)
{
	static int	start;
	static int	same;
	int			i;

	if (!check_buffer(buf, c_op, start))
		return ;
	i = ft_ncmp(buf->previous, buf->current, 16);
	if (buf->previous[0] && buf->bytes == 16 && !i)
	{
		if (!same)
			write(1, "*\n", 2);
	}
	else
	{
		buffer_else(c_op, start, buf);
		same = write(1, "\n", 1) - 1;
	}
	start += buf->bytes;
}
