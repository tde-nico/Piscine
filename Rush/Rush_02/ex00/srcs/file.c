#include "ft.h"

void	update_file(char *file_name)
{
	int		fd;

	fd = open("source", O_WRONLY);
	if (fd < 0)
		return ;
	while (*file_name)
	{
		write(fd, file_name, 1);
		file_name++;
	}
	close(fd);
}

void	ft_putstr_out(char *str, int out)
{
	while (*str)
	{
		write(out, str, 1);
		str++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	get_file_size(char *path)
{
	int		fd;
	int		bytes;
	int		file_size;
	char	buffer;

	file_size = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, &buffer, 1);
		file_size++;
	}
	close(fd);
	return (file_size);
}

char	*get_file_content(char *path)
{
	int		file_descriptor;
	int		bytes;
	char	buffer;
	char	*content;
	int		file_size;

	file_size = get_file_size(path);
	content = malloc(sizeof(*content) * file_size + 1);
	file_descriptor = open(path, O_RDONLY);
	if (file_descriptor < 0 || content == NULL)
		return (NULL);
	bytes = 0;
	while (bytes < file_size)
	{
		read(file_descriptor, &buffer, 1);
		content[bytes++] = buffer;
	}
	content[bytes] = '\0';
	close(file_descriptor);
	return (content);
}

int	ft_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (c != charset[i] && charset[i] != '\0')
		i++;
	if (charset[i] != '\0')
		return (0);
	return (1);
}

int	len(char *str, int i, char *charset)
{
	int	j;

	j = 0;
	while (ft_charset(str[i], charset) && str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int	wc(char *str, char *charset)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] && charset[0])
	{
		while (ft_charset(str[i], charset) == 0)
			i++;
		if (str[i])
			nbr++;
		while (ft_charset(str[i], charset) == 1 && str[i] != '\0')
			i++;
	}
	if (!(charset[0]))
		return (1);
	return (nbr);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	k = 0;
	i = 0;
	tab = malloc(sizeof(*tab) * (wc(str, charset) + 1));
	if (!tab)
		return (0);
	while (i < wc(str, charset) && str[0] != '\0')
	{
		j = 0;
		while (ft_charset(str[k], charset) == 0 && str[k])
			k++;
		tab[i] = malloc(sizeof(char) * len(str, k, charset) + 1);
		if (!tab[i])
			return (0);
		while (ft_charset(str[k], charset) == 1 && str[k])
			tab[i][j++] = str[k++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int	ft_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	len_str_join(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	if (size <= 0)
		return (0);
	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	return (len + (size - 1) * ft_strlen(sep));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str_join;
	int		len;

	i = 0;
	len = len_str_join(size, strs, sep);
	str_join = malloc(sizeof(char) * (len + 100));
	if (!str_join)
		return (NULL);
	while (i < len)
		str_join[i++] = 0;
	str_join[len] = '\0';
	if (!size)
		return (str_join);
	i = 0;
	while (i < size)
	{
		ft_strcat(str_join, strs[i]);
		if (i < size - 1)
			ft_strcat(str_join, sep);
		i++;
	}
	return (str_join);
}

int	ft_atoi(char *s)
{
	int	num;

	num = 0;
	while (*s)
	{
		num = num * 10 + *s -48;
		s++;
	}
	return (num);
}


t_dict	get_dict(char *path)
{
	char	**s;
	int		i;
	t_dict	dict;

	s = ft_split(get_file_content(path), ":\n");
	dict.numbers = malloc(sizeof(char *) * ft_len(s)/2);
	dict.words = malloc(sizeof(char *) * ft_len(s)/2);
	i = 0;
	while (s[i] != '\0')
	{
		dict.numbers[i / 2] = malloc(ft_strlen(s[i]) * sizeof(char));
		dict.numbers[i / 2] = ft_split(s[i], " ")[0];
		dict.words[i / 2] = malloc(ft_strlen(s[i + 1]) * sizeof(char));
		dict.words[i / 2] = s[i + 1];
		i += 2;
	}
	return (dict);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	get_index(char *s, t_dict dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict.numbers[i])
	{
		j = 0;
		while (dict.numbers[i][j] == s[j])
		{
			j++;
			if (s[j] == '\0')
				return (i);
		}
		i++;
	}
	return (-1);
}

void	eval_tri(char hun, char ten, char one, t_dict dict)
{
	char	chars[3];

	chars[2] = 0;
	//printf("%c %c %c\n", hun, ten, one);
	if (hun - 48)
	{
		eval_tri('0', '0', hun, dict);
		ft_putstr(dict.words[get_index("100", dict)]);
	}
	if (ten - 48)
	{
		if (ten == '1')
		{
			chars[0] = ten;
			chars[1] = one;
			ft_putstr(dict.words[get_index(chars, dict)]);
		}
		else
		{
			chars[0] = ten;
			chars[1] = '0';
			//printf("%s\n", chars);
			ft_putstr(dict.words[get_index(chars, dict)]);
		}
	}

	//printf(" %c %c %c\n", hun, ten, one);
	if ((one - 48) && (ten - 49))
	{
		chars[0] = one;
		chars[1] = 0;
		ft_putstr(dict.words[get_index(chars, dict)]);
	}
}

char	*ft_itoa(int len)
{
	char	*s;
	int		i;

	s = malloc(sizeof(*s) * len + 2);
	s[0] = '1';
	i = 1;
	while (len+1 > i)
	{
		s[i] = '0';
		i++;
	}
	s[i] = '\0';
	//printf("\n%s\n", s);
	return (s);
}

int	eval(t_dict dict, char *num)
{
	int	i;
	int	len;
	int	section;

	i = 0;
	len = ft_strlen(num);
	section = len % 3;
	if (!section)
	{
		section = 3;
		eval_tri(*num, *(num + 1), *(num + 2), dict);
	}
	//printf("1\n");
	if (section == 2)
		eval_tri('0', *num, *(num + 1), dict);
	//printf("2\n");
	if (section == 1)
		eval_tri('0', '0', *num, dict);
	//printf("3\n");
	if (len / 3 && len != 3)
	{	
		ft_putstr(dict.words[get_index(ft_itoa(len - section), dict)]);
		if (!eval(dict, num + section))
			return (0);
	}
	return (1);
}





int	handler(char *num, char *file_name)
{
	t_dict	dict;

	dict = get_dict(file_name);
	
	if (!eval(dict, num))
		return (0);
	
	//printf("\n%d", get_index(dict, "19"));

	printf("\n%s\n", num);
	/*printf("%s\n", file_name);
	for (int i=0; i < 41; i++)
		printf("%s %s\n", dict.numbers[i], dict.words[i]);
	*/
	return (1);
}

int main(int argc, char **argv)
{
	char *file_name;

	if (argc < 2 || argc > 3)
	{
		ft_putstr_out("Error\n", 2);
		return (1);
	}
	if (argc == 3)
	{
		update_file(argv[2]);
		file_name = argv[2];
	}
	else
		file_name = ft_split(get_file_content("source"), "\n")[0];
	if (!handler(argv[1], file_name))
	{
		ft_putstr_out("Dict Error\n", 2);
		return (1);
	}
	return (0);
}






