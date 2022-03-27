/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:49:37 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/15 08:16:46 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr_out(char *str, int out)
{
	while (*str)
	{
		write(out, str, 1);
		str++;
	}
}

int	display_file_content(char *path)
{
	int		file_descriptor;
	int		bytes;
	char	buffer[1024];

	file_descriptor = open(path, O_RDONLY);
	if (file_descriptor < 0)
		return (0);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(file_descriptor, buffer, 1024);
		write(1, buffer, bytes);
	}
	close(file_descriptor);
	return (1);
}

int	opt_parse(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr_out("File name missing.\n", 2);
	else if (argc > 2)
		ft_putstr_out("Too many arguments.\n", 2);
	else
	{
		if (display_file_content(argv[1]))
			return (0);
		ft_putstr_out("Cannot read file.\n", 2);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	return (opt_parse(argc, argv));
}
