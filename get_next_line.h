/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbistami <mbistami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:27:08 by mbistami          #+#    #+#             */
/*   Updated: 2021/11/26 22:50:47 by mbistami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t length);
char	*ft_substr(const char *src, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const char *src, size_t len);
char	*ft_strchr(const char	*string, int searchChar);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t elementCount, size_t elementSize);
size_t	ft_strlen(const char *v);
char	*ft_strdup(const char *src);

#endif