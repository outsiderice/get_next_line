/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:11:48 by amagnell          #+#    #+#             */
/*   Updated: 2023/08/02 19:42:34 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s3 = malloc (sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s3)
		return (ft_free(s1));
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	while (*s && (*s != (char)c))
		s++;
	if (*s == (char)c || (char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_free(char *s)
{
	free(s);
	s = NULL;
	return (NULL);
}

size_t	ft_line_len(char *text)
{
	size_t	line_len;

	line_len = 0;
	while (text[line_len] != '\0' && text[line_len] != '\n')
		line_len++;
	if (text[line_len] == '\n')
		line_len++;
	return (line_len);
}
