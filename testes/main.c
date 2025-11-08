/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:40:29 by marvin            #+#    #+#             */
/*   Updated: 2025/11/06 18:40:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);	
			if (fd < 0)
				printf("%s\n", "Erro ao abrir arquivo\n");
			else
			{
				printf("%s\n", argv[i]);
				line = get_next_line(fd);
				while (line)
				{
					printf("%s", line);
					free(line);
					line = get_next_line(fd);
				}
			}
			printf("\n");
			close(fd);
			i++;
		}
	}
}
