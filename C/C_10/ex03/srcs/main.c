/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:46:52 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/09 17:32:15 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	error(char *program, char *filename, char *message)
{
	char	formated[500];
	int		length;

	ft_strcpy(formated, basename(program));
	ft_strcat(formated, ": ");
	ft_strcat(formated, filename);
	ft_strcat(formated, ": ");
	if (!message)
		ft_strcat(formated, strerror(errno));
	else
		ft_strcat(formated, message);
	ft_strcat(formated, "\n");
	length = 0;
	while (formated[length])
		length++;
	write(2, formated, length);
	return (errno);
}

int	read_file(char *filename, t_buffer *buf, int c_op, int *total)
{
	int			ret;
	const int	file = open(filename, O_RDONLY);

	if (file < 0)
		return (-1);
	*total += 1;
	ret = read(file, buf->current + buf->bytes, (16 - buf->bytes));
	while (ret > 0)
	{
		if (ret == 16 || buf->bytes + ret == 16)
		{
			buf->bytes = 16;
			ft_display_buffer(buf, c_op);
			buf->bytes = 0;
		}
		else
			buf->bytes += ret;
		ft_ncpy(buf->previous, buf->current, 16);
		buf->total += ret;
		ret = read(file, buf->current + buf->bytes, (16 - buf->bytes));
	}
	close(file);
	return (ret);
}

int	read_stdin(t_buffer *buf, int c_op)
{
	int		ret;

	ret = read(0, buf->current + buf->bytes, (16 - buf->bytes));
	while (ret > 0)
	{
		if (ret == 16 || buf->bytes + ret == 16)
		{
			buf->bytes = 16;
			ft_display_buffer(buf, c_op);
			buf->bytes = 0;
		}
		else
			buf->bytes += ret;
		ft_ncpy(buf->previous, buf->current, 16);
		buf->total += ret;
		ret = read(0, buf->current + buf->bytes, (16 - buf->bytes));
	}
	return (ret);
}

void	init_buffer(t_buffer *buffer)
{
	buffer->previous = malloc(sizeof(*buffer->previous) * 16);
	buffer->current = malloc(sizeof(*buffer->current) * 16);
	buffer->bytes = 0;
	buffer->total = 0;
}

int	main(int argc, char **argv)
{
	int			ret;
	int			c_op[2];
	int			i;
	t_buffer	buffer;

	init_buffer(&buffer);
	c_op[0] = 0;
	c_op[1] = 0;
	if (argc > 1 && ft_ncmp(argv[1], "-C", 2) == 0)
		c_op[0] = 1;
	if ((argc == 2 && c_op[0]) || (argc == 1 && c_op[0] == 0))
		ret = read_stdin(&buffer, c_op[0]);
	i = c_op[0];
	while (++i < argc)
		if (read_file(argv[i], &buffer, c_op[0], &c_op[1]) < 0)
			ret = error(argv[0], argv[i], NULL);
	if (buffer.bytes > 0)
		ft_display_buffer(&buffer, c_op[0]);
	if (buffer.total > 0)
		ft_display_buffer(NULL, c_op[0]);
	if (c_op[1] == 0 && ((c_op[0] && argc > 2) || (!c_op[0] && argc > 1)))
		error(argv[0], argv[argc - 1], "Bad file descriptor");
	free(buffer.previous);
	free(buffer.current);
	return (ret);
}
