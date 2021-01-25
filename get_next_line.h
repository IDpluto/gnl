/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:37:11 by dohlee            #+#    #+#             */
/*   Updated: 2021/01/25 16:37:12 by dohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct				s_buff
{
	int						fd;
	struct s_buff			*next;
	char					*buff;
}							t_buff;

int							get_next_line(int fd, char **line);
char						*ft_strjoin(char const *s1, char const *s2);
size_t						ft_strlen(const char *str);
int							str_line(char *str);
size_t						l_strlen(char *l_str);
char						*ft_lstrdup(char *str);
char						*get_save(char *save);
t_buff						*create_buffer(int fd);
t_buff						*find_fd(int fd, t_buff *save);

#endif
