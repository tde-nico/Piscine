/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:52:05 by tde-nico          #+#    #+#             */
/*   Updated: 2021/12/09 14:24:59 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <libgen.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
int		add_to_buffer(char *buffer, char cbuf, int len, int limit);
int		ft_atoi(char *str);
int		error(char *program, char *filename);
int		error_message(char *program, char *message);
int		illegal_offset(char *program, char *offset);
int		usage_info(char *program);

#endif
