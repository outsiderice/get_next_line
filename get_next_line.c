/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:31:31 by amagnell          #+#    #+#             */
/*   Updated: 2023/07/18 20:56:03 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dst);
}

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
	while (text_buffer[len] != '\n' && text_buffer[len] != '\0')
		len++;
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

char	*ft_update_text_buffer(char *s, unsigned int start, size_t len)
{
	char	*str;

	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) - start > len)
	{
		str = malloc (len + 1);
		if (str == NULL)
			return (NULL);
		str[len] = '\0';
		ft_memmove(str, s + start, len);
		return (str);
	}
	str = malloc (ft_strlen(s) - start + 1);
	if (str == NULL)
		return (NULL);
	ft_memmove(str, s + start, ft_strlen(s) - start);
	str[ft_strlen(s) - start] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text_buffer = NULL;
	size_t		len;
	size_t		line_len;

	line_len = 0;
	line = NULL;
	if (fd == '\0')
	{
		free(text_buffer);
		text_buffer = NULL;
		return (NULL);
	}
	text_buffer = ft_get_text_buffer(fd, text_buffer);
	while (text_buffer[line_len] != '\n' && text_buffer[line_len] != '\0')
		line_len++;
	line_len = line_len + 1;
	line = ft_get_line(text_buffer, line);
	printf("line_len: %zu\n", line_len);
	len = ft_strlen(text_buffer) - line_len;
	text_buffer = ft_update_text_buffer(text_buffer, (int)ft_strchr(text_buffer, '\n'), len);
	printf("update is:%s\n", text_buffer);
	printf("return line:%s\n", line);
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
