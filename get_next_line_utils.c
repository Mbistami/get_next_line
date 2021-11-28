/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbistami <mbistami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:31:14 by mbistami          #+#    #+#             */
/*   Updated: 2021/11/28 04:16:33 by mbistami         ###   ########.fr       */
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
	size_t		len_src;
	char		*d;
	const char	*s;
	size_t		len;

	d = dst;
	s = src;
	len_src = ft_strlen(src);
	if (len_src + 1 < length)
	{
		len = len_src + 1;
		while (len--)
			*d++ = *s++;
	}
	else if (length != 0)
	{
		len = length;
		while (len--)
			*d++ = *s++;
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	max_len;

	if (!s1)
		return (NULL);
	max_len = ft_strlen(s1) + ft_strlen(s2);
		result = (char *) malloc((max_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (sizeof(result) <= 0)
		return (ft_strdup(""));
	ft_strlcpy(result, s1, max_len + 1);
	ft_strlcat(result, (char *)s2, (max_len + 1));
	return (result);
}
