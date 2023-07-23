/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:11:48 by amagnell          #+#    #+#             */
/*   Updated: 2023/07/20 20:37:54 by amagnell         ###   ########.fr       */
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
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s3 = malloc (sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
	{
		free(&s1);
		return (NULL);
	}
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	while (*s && (*s != (char)c))
		s++;
	if (*s == (char)c || (char)c == '\0')
		return((char *)s);
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

void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	i = 0;
	if (len)
	{
		if (a < b)
		{
			while (len--)
				b[len] = a[len];
		}
		else if (b < a)
		{
			while (i < len)
			{
				b[i] = a[i];
				i++;
			}
		}
	}
	return (dst);
}
