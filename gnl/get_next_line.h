/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:16:29 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/02 13:37:57 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_till_n(int fd, char *holder);
char	*ft_free(char **str);
char	*ft_get_line(char *holder);
char	*ft_subs_line_from_holder(char *holder);
char	*ft_strjoiner(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *stack, int needle);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif