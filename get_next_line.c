/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbistami <mbistami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:37:00 by mbistami          #+#    #+#             */
/*   Updated: 2021/11/27 02:11:18 by mbistami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strchr(const char	*string, int searchChar)
{
	char	*s;
	int		i;

	s = (char *)string;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)searchChar)
			return (&s[i]);
		i++;
	}
	if (s[i] == '\0' && (char)searchChar == '\0')
		return (&s[i]);
	return (NULL);
}

char	*ft_gnl_process(char **string)
{
	char	*to_return;
	size_t	len;
	size_t	i;
	char	*main_string;

	main_string = *string;
	i = 0;
	len = 0;
	while (main_string[i] && main_string[i] != '\n')
		i++;
	to_return = ft_substr(*string, 0, i + 1);
	to_return[i + 1] = '\0';
	*string = ft_substr(*string, i + 1, ft_strlen(*string));
	return (to_return);
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
	ft_strlcpy(result, s1, max_len + 1);
	ft_strlcat(result, (char *)s2, (max_len + 1));
	return (result);
}

size_t	ft_strlen(const char *v)
{
	int	counter;

	counter = 0;
	while (*(v + counter))
		counter++;
	return (counter);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	size_t		b_size;
	static char	*to_return;
	int			read_res;

	if (fd <= 0 || fd >= 4)
		return (NULL);
	b_size = BUFFER_SIZE + 1;
	buffer = malloc(b_size + 1);
	buffer[b_size + 1] = '\0';
	read_res = 1;
	while (read_res && ft_strchr(buffer, 10) == NULL)
	{
		read_res = read(fd, buffer, b_size);
		if (read_res == -1)
		{
			free(buffer);
			return (NULL);
		}
		printf("%d", read_res);
		if (!read_res)
			return (NULL);
		buffer[read_res] = '\0';
		if (to_return <= 0)
		{
			to_return = malloc(ft_strlen(buffer) + 1);
			ft_strlcpy(to_return, buffer, ft_strlen(buffer) + 1);
		}
		else
		{
			to_return = ft_strjoin(to_return, buffer);
			if ((size_t)read_res < b_size)
				break ;
		}
	}
	return (ft_gnl_process(&to_return));
}
