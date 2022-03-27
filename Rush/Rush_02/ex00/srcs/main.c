/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:55:53 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/11 10:01:31 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	div_string(int *i, char *str, char *argv, int *l)
{
	int		j;
	int		k;

	k = 0;
	j = 0;
	if (*i % 3 != 0)
		while (*i % 3 != 0)
		{
			str[k] = argv[*l];
			(*i)--;
			k++;
			(*l)++;
		}
	else
		while (j < 3)
		{
			str[k] = argv[*l];
			j++;
			k++;
			(*l)++;
		}
	str[k] = 0;
}

int		check_string(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		return (-1);
	if (argc > 2)
		return (-1);
	if (ft_strcmp(argv[1], "-p") == 0)
		argv[1] = get_nb_from_pipe();
	i = 0;
	if (argv[1][0] == '0')
		ft_remove_start_zeros(&argv[1]);
	if (argv[1][0] == '\0')
		return (-1);
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			return (-1);
		i++;
	}
	comp_str_dict(i);
	return (i);
}

void	print_words(int i, char **argv, char *str)
{
	int j;
	int k;
	int	l;

	j = i / 3;
	if (i % 3 != 0)
		j++;
	k = j;
	while (j != 0)
	{
		div_string(&i, str, argv[1], &l);
		if (j != k && ft_strcmp(str, "000") != 0)
			write(1, ", ", 2);
		if (j == 1 && ft_strcmp(str, "000") != 0 && str[0] == '0' && k != 1)
			write(1, "and ", 4);
		print_number(str);
		if (ft_strcmp(str, "000") != 0 && j != 1)
			ft_print_separator_with_space(j);
		j--;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*str;

	if ((i = check_string(argc, argv)) == -1)
		ft_error();
	if (!(str = (char *)malloc(sizeof(char) * 4)))
		ft_error();
	print_words(i, argv, str);
}
