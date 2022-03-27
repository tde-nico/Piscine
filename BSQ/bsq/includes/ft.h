/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:37:55 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/14 15:11:23 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map {
	int		w;
	int		h;
	char	*source;
	char	**grid;
	char	tr[3];
}	t_map;

typedef struct s_sol {
	int	size;
	int	x;
	int	y;
}	t_sol;

int		load_map(char *path, t_map *map);
void	free_map(t_map *map);
void	process_map(t_map *map, t_sol *sol);
int		parse_first_line(t_map *map, char *line, int len);
int		parse_normal_line(t_map *map, char *line, int len);
int		check(t_map *map, int *w);
int		process_lines(t_map *map, int i, char *file_content, int total);
int		parse_map(int fd, t_map *map);
int		get_file_content(int fd, char **file_content, int *total);
void	process_args(t_map *map, t_sol *sol, int argc, char **argv);
int		find_sol(t_sol *sol, t_map *map);
void	test_sol(t_sol *sol, t_sol *try, t_map *map);
int		test(t_sol *try, t_map *map);
int		test_success(t_sol *try, t_map *map);
int		fail(t_sol *try, t_map *map);
char	*ft_strncpy(char *dest, char *src, int n);
char	*allocate(char *origin, char new_char, int old_len, int len);
int		ft_atoi(char *str, int n, int *res);
int		count_lines(t_map *map);

#endif
