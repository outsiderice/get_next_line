/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:32:48 by amagnell          #+#    #+#             */
/*   Updated: 2023/07/26 19:14:27 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("variable_nl.txt", O_RDONLY);
	line = get_next_line(fd);
	if (fd == -1)
		return (1);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("line in main:<%s>", line);
	}
	close(fd);
	return (0);
}
