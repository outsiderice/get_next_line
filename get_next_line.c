/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:31:31 by amagnell          #+#    #+#             */
/*   Updated: 2023/08/02 19:41:17 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_text_buffer(int fd, char *text_buffer)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(text_buffer));
	buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			text_buffer = ft_strjoin(text_buffer, buffer);
		}
	}
	if (bytes_read < 0)
	{
		free(text_buffer);
		text_buffer = NULL;
	}
	free(buffer);
	return (text_buffer);
}

char	*ft_get_line(char *text_buffer, size_t len)
{
	char	*line;
	size_t	i;

	i = 0;
	if (len == 0)
		return (NULL);
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	while (text_buffer[i] != '\0' && text_buffer[i] != '\n')
	{
		line[i] = text_buffer[i];
		i++;
	}
	if (text_buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_text_buffer(char *s)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	i = ft_line_len(s);
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
	{
		free(s);
		return (NULL);
	}
	while (s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text_buffer = NULL;
	size_t		len;
	size_t		line_len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text_buffer = ft_get_text_buffer(fd, text_buffer);
	if (!text_buffer)
		return (NULL);
	line_len = ft_line_len(text_buffer);
	line = ft_get_line(text_buffer, line_len);
	if (!line)
	{
		free(text_buffer);
		text_buffer = NULL;
		return (NULL);
	}
	len = ft_strlen(text_buffer) - line_len;
	text_buffer = ft_update_text_buffer(text_buffer);
	return (line);
}
