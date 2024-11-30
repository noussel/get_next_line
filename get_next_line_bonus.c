/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:21:55 by nel-khad          #+#    #+#             */
/*   Updated: 2024/11/30 16:05:51 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char **tmp, int n)
{
	char	*line;
	char	*new_tmp;

	line = ft_substr(*tmp, 0, n + 1);
	new_tmp = ft_substr(*tmp, n + 1, ft_strlen(*tmp) - n);
	free(*tmp);
	*tmp = new_tmp;
	return (line);
}

char	*last_line(char **tmp)
{
	char	*next_line;

	next_line = ft_strdup(*tmp);
	free(*tmp);
	*tmp = NULL;
	return (next_line);
}

char	*read_line(char **tmp, char *buf, int fd)
{
	int		n;
	int		c;
	char	*next_line;

	c = 1;
	n = -1;
	while (c > 0 && n == -1)
	{
		c = read(fd, buf, BUFFER_SIZE);
		buf[c] = '\0';
		*tmp = ft_strjoin(*tmp, buf);
		n = ft_strchr(*tmp);
	}
	free(buf);
	if (n != -1 && c > 0)
	{
		next_line = get_line(tmp, n);
		return (next_line);
	}
	if (*tmp[0] != '\0' && n == -1 && c >= 0)
		return (last_line(tmp));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*tmp[1024];
	char		*next_line;
	char		*buf;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = ft_strchr(tmp[fd]);
	if (n != -1)
	{
		next_line = get_line(&tmp[fd], n);
		free(buf);
		return (next_line);
	}
	next_line = read_line(&tmp[fd], buf, fd);
	if (next_line)
		return (next_line);
	free(tmp[fd]);
	tmp[fd] = NULL;
	return (NULL);
}

int	main(void)
{
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	char *line = get_next_line(fd1);
	printf("line 11:%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("line 22:%s\n", line);
	free(line);
	line = get_next_line(fd1);
	printf("line 21:%s\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("line 22:%s\n", line);
	free(line);
}