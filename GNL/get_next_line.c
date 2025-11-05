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
    if (tmp_stash == NULL)
        return (NULL);
	bytes = 1;
	while(bytes != '\0' && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, tmp_stash, BUFFER_SIZE);
		if(bytes < 0)
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

char ft_get_line(char *buffer)
{
	int i;
	char *line;

	i = 0;
	if(buffer[i] == NULL)
		return (NULL);
	line = malloc(sizeof());
	if(line == NULL)
		return (NULL);






	return(line);
}

char	*get_next_line(int fd)
{
    static char *buf;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buf = ft_read_save(fd, buffer);
    if (buf == NULL)
        return (NULL);
	line = ft_get_line();
	line = ft_clean();
    return (line);
}