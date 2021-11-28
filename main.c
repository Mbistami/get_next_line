/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbistami <mbistami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:26:04 by mbistami          #+#    #+#             */
/*   Updated: 2021/11/28 11:21:54 by mbistami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("text_file.txt", O_RDONLY);
	
	printf("%s", get_next_line(1000));
	printf("%s", get_next_line(fd));
	//printf("%zu", ft_strlen("\n\0"));
	// printf("%s", get_next_line(0));
	// printf("%s", get_next_line(0));
	
}
