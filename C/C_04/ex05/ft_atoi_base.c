/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:49:39 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/06 09:06:44 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_check(char *base)
{
	int	i;
	int	j;

	if ((base[0] == '\0') || (base[1] == '\0'))
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] == '-') || (base[i] == '+'))
			return (0);
		if ((base[i] <= 32) || (base[i] > 126))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_base_index(char *base, char match)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == match)
			return (i);
		i++;
	}
	return (-1);
}

long int	base_to_int(char *str, char *base, int start, int end)
{
	int			i;
	long int	nb;
	int			size;
	int			base_size;

	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	i = start;
	size = 1;
	while (i < start + end - 1)
		i++;
	nb = 0;
	while (i >= start)
	{
		nb += get_base_index(base, str[i]) * size;
		size *= base_size;
		i--;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	long int	nb;
	int			i;
	int			sign;
	int			count;

	i = 0;
	count = 0;
	sign = 1;
	if (!(base_check(base)))
		return (0);
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
			i++;
	while ((str[i] == '-') || (str[i] == '+'))
		if (str[i++] == '-')
			count++;
	if (count % 2 == 1)
		sign = -1;
	count = 0;
	while (get_base_index(base, str[i + count]) != -1)
		count++;
	nb = base_to_int(str, base, i, count);
	return (nb * sign);
}
