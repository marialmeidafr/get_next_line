/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:34:48 by marvin            #+#    #+#             */
/*   Updated: 2025/11/03 16:34:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_save(int fd, char *buffer)
{
	char	*tmp_stash;
	int		bytes;

	tmp_stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_stash)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, tmp_stash, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(tmp_stash);
			free(buffer);
			return (NULL);
		}
		tmp_stash[bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp_stash);
	}
	free(tmp_stash);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean_stash(char *buffer)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_stash = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (new_stash == NULL)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_stash[j++] = buffer[i++];
	new_stash[j] = '\0';
	free(buffer);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_read_save(fd, buf);
	if (buf == NULL)
		return (NULL);
	line = ft_get_line(buf);
	buf = ft_clean_stash(buf);
	return (line);
}
