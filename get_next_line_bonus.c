/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:38:55 by dohlee            #+#    #+#             */
/*   Updated: 2021/01/25 21:38:59 by dohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int					get_next_line(int fd, char **line)
{
	int				rd;
	static	t_buff	*save = NULL;
	t_buff			*tmp_buffer;
	char			*file;

	rd = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0
		|| ((!save && !(save = create_buffer(fd)))
		|| !(tmp_buffer = find_fd(fd, save)))
		|| (!(file = malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while (!str_line(tmp_buffer->buff) && rd != 0)
	{
		if ((rd = read(fd, file, BUFFER_SIZE)) == -1)
		{
			free(file);
			return (-1);
		}
		file[rd] = '\0';
		tmp_buffer->buff = ft_strjoin(tmp_buffer->buff, file);
	}
	free(file);
	*line = ft_lstrdup(tmp_buffer->buff);
	tmp_buffer->buff = get_save(tmp_buffer->buff);
	return ((int)(rd != 0));
}

t_buff				*create_buffer(int fd)
{
	t_buff			*tmp;

	if (!(tmp = malloc(sizeof(t_buff))))
		return (NULL);
	tmp->fd = fd;
	if (!(tmp->buff = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	tmp->buff[0] = '\0';
	tmp->next = NULL;
	return (tmp);
}

t_buff				*find_fd(int fd, t_buff *save)
{
	if (save->fd == fd)
		return (save);
	if (save->next == NULL)
		return (save->next = create_buffer(fd));
	return (find_fd(fd, save->next));
}

char				*get_save(char *save)
{
	char	*ptr;
	int		i;
	int		j;
	int		l_save;

	i = l_strlen(save);
	j = 0;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	l_save = ft_strlen(save);
	if (!(ptr = malloc(sizeof(char) * (l_save + 1))))
		return (0);
	i++;
	while (save[i])
		ptr[j++] = save[i++];
	ptr[j] = '\0';
	free(save);
	return (ptr);
}
