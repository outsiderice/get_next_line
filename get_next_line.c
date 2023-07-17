/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:31:31 by amagnell          #+#    #+#             */
/*   Updated: 2023/07/15 17:44:53 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_text_buffer(int fd, char *text_buffer)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	int		a;

	printf("I'm about to assign text to text buffer, text_buffer = %s\n", text_buffer);
	bytes_read = 1;
	buffer[0] = '\0';
	while (bytes_read > 0)
	{
		printf("did I segfault here?\n");
		if (ft_strchr(buffer, '\n'))
			break;
		else
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			text_buffer = ft_strjoin(text_buffer, buffer);
		}
	}
	a = printf("text buffer now:%s\n", text_buffer);
	return (text_buffer);
}

char	*ft_get_line(char *text_buffer, char *line)
{
	int	len;

	len = 0;
	printf("about to enter while loop\n");
	while (text_buffer[len] != '\n')
	{
		printf("in this loop we count until we find a line end\n");
		len++;
	}
	printf("len is %i\n", len);
	line = malloc(len + 2);
	if (line == NULL)
		return (NULL);
	len = 0;
	while (text_buffer[len] != '\n')
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
	int		past_len;
	int		len;

	past_len = 0;
	len = 0;
	printf("text_bufer is: %s\n", text_buffer);
	while (text_buffer[past_len] != '\n')
		past_len++;
	while (*text_buffer)
	{
		text_buffer++;
		len++;
	}
	printf("past_len is:%i\n", past_len);
	printf("len is: %i\n", len);
	update = malloc (len - past_len + 2);
	if (update == NULL)
		return (NULL);
	len = 0;
	while (*text_buffer && *update)
	{
		update[len] = text_buffer[past_len];
		past_len++;
		len++;
	}
	return (update);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text_buffer = NULL;
	int	a;

	line = NULL;
	if (fd == '\0')
	{
		free(text_buffer);
		text_buffer = NULL;
		return (NULL);
	}
	text_buffer = ft_get_text_buffer(fd, text_buffer);
	printf("to the 2nd function\n");
	printf("line is:%s\n", line);
	a = printf("%s", text_buffer);
	printf("and this long: %i\n", a);
	line = ft_get_line(text_buffer, line);
	text_buffer = ft_update_text_buffer(text_buffer);
	return (line);
}
/*
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
*/
/*
might have a problem with that strjoin malloc, gotta look at it again later
ft_update_text is substr.
*/
