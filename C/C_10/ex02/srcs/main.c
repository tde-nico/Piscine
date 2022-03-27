/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:49:30 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/09 09:57:00 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_opt(int argc, char **argv)
{
	int		c_op;

	if (argc < 2)
		return (usage_info(argv[0]));
	else if (argc == 2 && ft_strcmp("-c", argv[1]) == 0)
		return (error_message(argv[0], "option requires an argument -- c\n"));
	else if (ft_strcmp("-c", argv[1]) != 0)
		return (usage_info(argv[0]));
	c_op = ft_atoi(argv[2]);
	if (c_op < 0)
		illegal_offset(argv[0], argv[2]);
	return (c_op);
}

int	header(char *filename, int output)
{
	char	formated[500];
	int		length;

	formated[0] = '\0';
	if (output > 0)
		ft_strcat(formated, "\n");
	ft_strcat(formated, "==> ");
	ft_strcat(formated, filename);
	ft_strcat(formated, " <==\n");
	length = 0;
	while (formated[length])
		length++;
	write(1, formated, length);
	return (output + 1);
}

int	read_file(int file, int c_op_total[2], int *output, char *filename)
{
	char	*buffer;
	int		len_ret[2];
	char	cbuf;

	len_ret[0] = 0;
	if (file < 0)
		return (-1);
	buffer = malloc(sizeof(*buffer) * c_op_total[0]);
	len_ret[1] = read(file, &cbuf, 1);
	while (len_ret[1] > 0)
	{
		len_ret[0] = add_to_buffer(buffer, cbuf, len_ret[0], c_op_total[0]);
		len_ret[1] = read(file, &cbuf, 1);
	}
	if ((len_ret[0] >= 0 || len_ret[1] == -1) && c_op_total[1] > 1)
		*output = header(filename, *output);
	if (c_op_total[0] > len_ret[0])
		write(1, buffer, len_ret[0]);
	else
		write(1, (buffer + len_ret[0] - c_op_total[0]), c_op_total[0]);
	close(file);
	free(buffer);
	if (len_ret[1] == -1 || len_ret[1] >= 0)
		return (0);
	return (-1);
}

int	read_stdin(int c_op)
{
	char	*buffer;
	int		len;
	char	cbuf;
	int		ret;

	len = 0;
	buffer = malloc(sizeof(*buffer) * c_op + 1);
	ret = read(0, &cbuf, 1);
	while (ret > 0)
	{
		len = add_to_buffer(buffer, cbuf, len, c_op);
		ret = read(0, &cbuf, 1);
	}
	if (ret == 0 && len > 0)
		write(1, buffer, len);
	free(buffer);
	return (ret);
}

int	main(int argc, char **argv)
{
	int	ret;
	int	c_op_total[2];
	int	i;
	int	output;
	int	file;

	output = 0;
	c_op_total[1] = argc - 3;
	ret = 0;
	c_op_total[0] = get_opt(argc, argv);
	if (c_op_total[0] < 0)
		return (1);
	if (argc == 3)
		ret = read_stdin(c_op_total[0]);
	i = 3;
	while (i < argc)
	{
		file = open(argv[i], 'r');
		if (read_file(file, c_op_total, &output, argv[i]) < 0)
			ret = error(argv[0], argv[i]);
		i++;
	}
	return (ret);
}
