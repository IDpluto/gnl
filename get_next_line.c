/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohlee <dohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:26:54 by dohlee            #+#    #+#             */
/*   Updated: 2021/01/10 22:52:03 by dohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>

char	*get_save(char *save)
{
    char	*ptr;
    int		i;
    int		j;
    int     l_save;

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

int					get_next_line(int fd, char **line)
{
	int			rd;
	static t_buff   *save = NULL;
    t_buff      *tmp_buffer;
    char        *file;

	rd = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((!save && !(save = creat_buffer(fd)))
                    || !(tmp_buffer = find_fd(fd, save)))
        return (-1);

  if(!(file = malloc(sizeof (char) * (BUFFER_SIZE +1))))
    return (-1);

    while (!str_segment(tmp_buffer->buff) && rd != 0)
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
	*line = ft_strdup(tmp_buffer->buff);
	tmp_buffer->buff = get_save(tmp_buffer->buff);
	if (rd == 0)
		return (0);
	return (1);
}

t_buff              *creat_buffer(int fd)
{
    t_buff          *tmp;

    if (!(tmp = malloc(sizeof(t_buff))))
        return (NULL);
    tmp->fd = fd;
	if(!(tmp->buff = malloc(BUFFER_SIZE + 1)))
		return (NULL);
    tmp->buff[0] = '\0';
    tmp->next = NULL;
    return (tmp);
}

t_buff              *find_fd(int fd, t_buff *save)
{
   if (save->fd == fd)
       return (save);
   if (save->next == NULL)
       return (save->next = creat_buffer(fd));
   return (find_fd(fd, save->next));
}

/*int main(void)
{
	char *line = 0;
	int ret;
	int fd;

	fd = open("testfile2", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}*/
