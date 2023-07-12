/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:31:31 by amagnell          #+#    #+#             */
/*   Updated: 2023/07/12 20:11:25 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_text_buffer(int fd, char *text_buffer)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
//	char	*temp;

	bytes_read = 1;
	buffer[0] = '\0';
	while(!ft_strchr(text_buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read > 0)
			text_buffer = ft_strjoin(text_buffer, buffer);
	}
	return (text_buffer);
}

char	*ft_get_line(char *text_buffer, char *line)
{
	int	len;

	len = 0;
	while(text_buffer[len] != '\n')
		len++;
	line = malloc(len + 2);
	if(line == NULL)
		return (NULL);
	len = 0;
	while(text_buffer[len] != '\n')
	{
		line[len] = text_buffer[len];
		len++;
	}
	line[len] = '\n';
	len++;
	line[len] = '\0';
	return (line);
}

char	*ft_update_text_buffer(char *text_buffer)
{
	char	*update;
	int		len;
	int		len2;

	len = 0;
	len2 = 0;
	while(text_buffer[len] != '\n' || text_buffer[len] != '\0')
		len++;
	len = len + 1;
	while(text_buffer[len2])
		len2++;
	update = malloc (len2 - len + 1);
	if(update == NULL)
		return (NULL);
	len2 = 0;
	while (text_buffer[len] && update[len2])
	{
		update[len2] = text_buffer[len];
		len++;
		len2++;
	}
	return(update);
}
	
char	*get_next_line(int fd)
{
	char		*line;
	static char	*text_buffer = NULL;

	line = NULL;
	if( fd == '\0' || text_buffer == NULL)
	{
		free(text_buffer);
		text_buffer = NULL;
		return (NULL);
	}
	text_buffer = ft_get_text_buffer(fd, text_buffer);
	line = ft_get_line(text_buffer, line);
	text_buffer = ft_update_text_buffer(text_buffer);
	return(line);
}

int	main(void)
{
	int	fd;
	char	*line;

	line = "a";
	fd = open("text.txt", O_RDONLY);
	while(line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}

/*
might have a problem with that strjoin malloc, gotta look at it again later
ft_update_text is substr.
*/
