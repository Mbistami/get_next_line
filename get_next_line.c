/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbistami <mbistami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:37:00 by mbistami          #+#    #+#             */
/*   Updated: 2021/11/28 11:46:53 by mbistami         ###   ########.fr       */
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

size_t	ft_strlen(const char *v)
{
	size_t	counter;

	counter = 0;
	while (*(v + counter))
		counter++;
	return (counter);
}

char	*ft_gnl_extract_line(char **main_string, char **static_stirng, size_t i)
{
	char	*to_return;

	if (i == ft_strlen(*main_string))
	{
		*static_stirng = NULL;
		to_return = ft_strdup(*main_string);
		free(*main_string);
		*main_string = NULL;
		return (to_return);
	}
	else if (i + 1 <= ft_strlen(*main_string))
	{
		*static_stirng = ft_strdup(*main_string + i + 1);
		to_return = ft_substr(*main_string, 0, i + 1);
	}
	else
		return (NULL);
	free(*main_string);
	return (to_return);
}

char	*ft_gnl_process(char **string, int read_res)
{
	size_t	i;
	char	*main_string;

	main_string = ft_strdup(*string);
	i = 0;
	while (main_string[i] && main_string[i] != '\n')
		i++;
	if (ft_strlen(*string) <= 0 && read_res <= 0)
	{
		free(*string);
		free(main_string);
		*string = NULL;
		if (read_res == 0)
			return (NULL);
		else if (read_res < 0)
			return (NULL);
		else
			return (ft_strdup(""));
	}
	return (free(*string), ft_gnl_extract_line(&main_string, string, i));
}

char	*get_next_line(int fd)
{
	static char	*to_return;
	char		buffer[BUFFER_SIZE + 1];
	int			read_res;
	char		*tmp;

	read_res = -1;
	if ((fd < 0 || fd >= 1000) || (BUFFER_SIZE <= 0))
		return (NULL);
	if (to_return == NULL)
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		buffer[read_res] = '\0';
		to_return = ft_strdup(buffer);
	}
	while (read_res != 0)
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		buffer[read_res] = '\0';
		tmp = to_return;
		to_return = ft_strjoin(to_return, buffer);
		free(tmp);
		if (ft_strchr(to_return, '\n') != NULL || read_res == -1)
			break ;
	}
	return ((ft_gnl_process(&to_return, read_res)));
}
