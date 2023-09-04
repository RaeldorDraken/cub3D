/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:09:06 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/04 16:44:32 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

int	parser(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd);
	return (1);
}