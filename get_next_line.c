/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:21:55 by nel-khad          #+#    #+#             */
/*   Updated: 2024/11/28 13:57:12 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (n != -1)
	{
		next_line = get_line(tmp, n);
		return (next_line);
	}
	if (*tmp[0] != '\0' && n == -1 && c == 0)
		return (last_line(tmp));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*next_line;
	char		*buf;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!tmp)
		tmp = ft_strdup("");
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = ft_strchr(tmp);
	if (n != -1)
	{
		next_line = get_line(&tmp, n);
		free(buf);
		return (next_line);
	}
	next_line = read_line(&tmp, buf, fd);
	if (next_line)
		return (next_line);
	free(tmp);
	tmp = NULL;
	return (NULL);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int i = 1;
// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL )
// 	{
// 		printf("line %d : %s", i, line);
// 		free(line);
// 		i++;
// 	}
// }