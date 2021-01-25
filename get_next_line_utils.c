/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:36:59 by dohlee            #+#    #+#             */
/*   Updated: 2021/01/25 16:37:02 by dohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		s1_len;
	size_t		s2_len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		str[i++] = s2[j++];
	str[i] = '\0';
	free((char *)s1);
	return (str);
}

size_t			ft_strlen(const char *str)
{
	int			len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int				str_line(char *str)
{
	int			i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t			l_strlen(char *l_str)
{
	int			len;

	len = 0;
	if (!l_str)
		return (0);
	while (l_str[len] && l_str[len] != '\n')
		len++;
	return (len);
}

char			*ft_lstrdup(char *str)
{
	int			i;
	char		*ptr;
	int			n;

	i = l_strlen(str);
	if (!(ptr = malloc(sizeof(char) * (i + 1))))
		return (0);
	n = 0;
	while (n < i)
	{
		ptr[n] = str[n];
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}
