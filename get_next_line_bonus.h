#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
# endif

typedef struct				s_buff
{
	int						fd;
	struct	s_buff			*next;
	char					*buff;
}							t_buff;



int			get_next_line(int fd, char **line);
char		*ft_strjoin(char const *S1, char const *s2);
size_t		ft_strlen(const char *str);
int     str_segment(char *str);
size_t  l_strlen(char *l_str);
char    *ft_strdup(char *str);
char    *get_save(char *save);
t_buff    *creat_buffer(int fd);
t_buff    *find_fd(int fd, t_buff *save);

#endif
