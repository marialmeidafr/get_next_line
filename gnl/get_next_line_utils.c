/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:17:07 by marvin            #+#    #+#             */
/*   Updated: 2025/11/05 17:17:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	j;

	if (!s)
		return (NULL);
	j = (char)c;
	while (*s && *s != j)
		s++;
	if (*s == j)
		return ((char *) s);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	k = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[i])
		str[i++] = s2[k++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
