/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:19:57 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/02 17:13:21 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoiner(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	ft_free(&s1);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *stack, int needle)
{
	while (*stack && *stack != (char)needle)
		stack++;
	if (*stack == (char)needle)
		return ((char *)stack);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	if ((slen - start) < len)
		len = slen - start;
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	while ((start + i) < slen && i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_free(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	return (NULL);
}
