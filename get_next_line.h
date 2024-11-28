/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:14:33 by nel-khad          #+#    #+#             */
/*   Updated: 2024/11/28 13:50:50 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
ssize_t	ft_strlen(const char *str);
int		ft_strchr(const char *s);
char	*ft_substr(char const *s, unsigned int start, ssize_t len);
char	*get_next_line(int fd);

#endif