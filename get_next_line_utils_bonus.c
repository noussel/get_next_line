/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:14:09 by nel-khad          #+#    #+#             */
/*   Updated: 2024/11/28 14:03:51 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		l;
	int		i;
	char	*c;

	l = 0;
	i = 0;
	while (s1[l] != '\0')
	{
		l++;
	}
	c = (char *)malloc((l + 1) * sizeof(char));
	if (!c)
		return (NULL);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	c = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!c)
		return (NULL);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		c[i++] = s2[j++];
	}
	c[i] = '\0';
	free(s1);
	return (c);
}

ssize_t	ft_strlen(const char *str)
{
	ssize_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strchr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	if (s[i] == '\n')
		return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, ssize_t len)
{
	char	*c;
	ssize_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	c = malloc((len + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		c[i] = s[start];
		start++;
		i++;
	}
	c[i] = '\0';
	return (c);
}
