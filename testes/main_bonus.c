/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:01:07 by marvin            #+#    #+#             */
/*   Updated: 2025/11/07 20:01:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int		fd1 = open("test.txt", O_RDONLY);
	int		fd2 = open("teste.txt", O_RDONLY);
	char	*line1;
	char	*line2;

	if (fd1 < 0 || fd2 < 0)
		return (printf("Erro ao abrir arquivo\n"), 1);

	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (!line1 && !line2)
			return (0);
		if (line1)
		{
			printf("ARQUIVO 1: %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("ARQUIVO 2: %s", line2);
			free(line2);
		}
	}
	printf("\n");
	close(fd1);
	close(fd2);
	return (0);
}
