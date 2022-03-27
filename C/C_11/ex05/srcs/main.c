/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:45:53 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/15 09:34:43 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(int out, char *str)
{
	while (*str)
	{
		write(out, str, 1);
		str++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
			i++;
	while ((str[i] == '-') || (str[i] == '+'))
		if (str[i++] == '-')
			sign = -sign;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putstr(1, "8");
	}
	else if (nb < 0)
	{
		ft_putstr(1, "-");
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		c = 48 + nb % 10;
		write(1, &c, 1);
	}
}

int	operate(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
		return (a / b);
	if (op == '%')
		return (a % b);
	return (0);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	operator;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		operator = argv[2][0];
		if (operator == '/' && b == 0)
		{
			ft_putstr(2, "Stop : division by zero\n");
			return (1);
		}
		if (operator == '%' && b == 0)
		{
			ft_putstr(2, "Stop : modulo by zero\n");
			return (1);
		}
		ft_putnbr(operate(a, b, operator));
		ft_putstr(1, "\n");
	}
	return (0);
}
