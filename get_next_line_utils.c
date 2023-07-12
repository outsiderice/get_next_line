/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:11:48 by amagnell          #+#    #+#             */
/*   Updated: 2023/07/12 19:34:56 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = -1;
	s3 = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*a;

	i = 0;
	a = (char *)s;
	while (a[i] != '\0')
	{
		if (a[i] == (char)c)
			return (&a[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&a[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
