/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:14:20 by nel-khad          #+#    #+#             */
/*   Updated: 2024/11/26 20:14:21 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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