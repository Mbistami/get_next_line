/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbistami <mbistami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:26:04 by mbistami          #+#    #+#             */
/*   Updated: 2021/11/29 10:07:17 by mbistami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char *str;

	fd = open("./gnlTester/files/empty", O_RDONLY);
	
	// while ((str = get_next_line(1)) != NULL)
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	
	//printf("%zu", ft_strlen("\n\0"));
	// printf("%s", get_next_line(0));
	// printf("%s", get_next_line(0));
	
}
