/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:55:59 by tde-nico          #+#    #+#             */
/*   Updated: 2021/11/29 11:13:58 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanum(char c)
{
	if (('0' <= c) && (c <= '9'))
		return (1);
	if (('A' <= c) && (c <= 'Z'))
		return (1);
	if (('a' <= c) && (c <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	alpha;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (('a' <= str[i]) && (str[i] <= 'z') && !(word))
			str[i] = str[i] - 32;
		if (('A' <= str[i]) && (str[i] <= 'Z') && word)
			str[i] = str[i] + 32;
		alpha = 0;
		if (!(is_alphanum(str[i])))
			word = 0;
		else
			word = 1;
		i++;
	}
	return (str);
}
