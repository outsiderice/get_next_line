/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:43:53 by amagnell          #+#    #+#             */
/*   Updated: 2023/07/26 21:16:41 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000000
# endif

char	*get_next_line(int fd);
char	*ft_get_text_buffer(int fd, char *text_buffer);
char	*ft_get_line(char *text_buffer, size_t len);
char	*ft_update_text_buffer(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_free(char *s);
size_t	ft_line_len(char *text);

#endif
