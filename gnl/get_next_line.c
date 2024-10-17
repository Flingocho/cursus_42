/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:05:20 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/02 13:38:36 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((holder && !ft_strchr(holder, '\n')) || !holder)
		holder = ft_read_till_n(fd, holder);
	if (!holder)
		return (NULL);
	line = ft_get_line(holder);
	if (!line)
		return (ft_free(&holder));
	holder = ft_subs_line_from_holder(holder);
	return (line);
}

char	*ft_read_till_n(int fd, char *holder)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&holder));
	buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			holder = ft_strjoiner(holder, buffer);
		}
	}
	free(buffer);
	if (bytes_read == -1)
		return (ft_free(&holder));
	return (holder);
}

char	*ft_get_line(char *holder)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(holder, '\n');
	len = (ptr - holder) + 1;
	line = ft_substr(holder, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_subs_line_from_holder(char *holder)
{
	char	*new_holder;
	char	*ptr;
	int		len;

	ptr = ft_strchr(holder, '\n');
	if (!ptr)
	{
		new_holder = NULL;
		return (ft_free(&holder));
	}
	else
		len = (ptr - holder) + 1;
	if (!holder[len])
		return (ft_free(&holder));
	new_holder = ft_substr(holder, len, ft_strlen(holder) - len);
	ft_free(&holder);
	if (!new_holder)
		return (NULL);
	return (new_holder);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/