/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbistami <mbistami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:31:14 by mbistami          #+#    #+#             */
/*   Updated: 2021/11/26 23:12:37 by mbistami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int		i;
	unsigned int		dest_l;
	unsigned int		src_l;

	dest_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	i = 0;
	if (dstsize == 0 || dstsize <= dest_l)
		return (dstsize + src_l);
	while (i < src_l && i < dstsize - dest_l - 1)
	{
		dst[dest_l + i] = src[i];
		i++;
	}
	dst[dest_l + i] = '\0';
	return (src_l + dest_l);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t length)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (len_src + 1 < length)
		ft_memcpy(dst, src, len_src + 1);
	else if (length != 0)
	{
		ft_memcpy(dst, src, length - 1);
		dst[length - 1] = '\0';
	}
	return (len_src);
}

char	*ft_substr(const char *src, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;
	size_t	len_src;

	i = 0;
	if (!src)
		return (NULL);
	len_src = ft_strlen(src);
	if (len_src < len)
		r = (char *)malloc((len_src + 1) * sizeof(*src));
	else
		r = (char *)malloc((len + 1) * sizeof(*src));
	if (!r)
		return (NULL);
	while (i < len)
	{
		if (!src[i + start])
			return (r);
		r[i] = src[i + start];
		i++;
	}
	r[i] = '\0';
	return (r);
}

void	*ft_memcpy(void *dest, const char *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (len--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*s;
	char	*source;
	size_t	len;

	source = (char *)src;
	len = ft_strlen(source);
	s = (char *) malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_strlcpy(s, source, len + 1);
	return (s);
}
