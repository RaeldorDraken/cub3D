/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:09:06 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/11 18:13:39 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

static int	cb_store_data(t_game *game, char *input, int map_count)
{
	int	i;

	i = cb_get_first_char(input, 0);
	if (input[i] == 'N')
		game->text_paths[NORTH] = ft_strdup(input);
	else if (input[i] == 'S')
		game->text_paths[SOUTH] = ft_strdup(input);
	else if (input[i] == 'W')
		game->text_paths[WEST] = ft_strdup(input);
	else if (input[i] == 'E')
		game->text_paths[EAST] = ft_strdup(input);
	else if (input[i] == 'F')
		game->f = ft_strdup(input);
	else if (input[i] == 'C')
		game->c = ft_strdup(input);
	else if (input[i] == '1' || input[i] == '0')
	{
		game->map[map_count] = ft_strdup(input);
		map_count++;
	}
	return (map_count);
}

int	cb_count_lines(char **file, int count)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(*file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (cb_get_next_line(fd, &line))
	{
		i = cb_get_first_char(line, 0);
		if (line[i] == '1' || line[i] == '0')
			count++;
		free(line);
	}
	free(line);
	close(fd);
	return (count);
}

int	cb_parser(t_game *game)
{
	int		fd;
	int		map_count;
	char	*line;

	fd = open(game->file, O_RDONLY);
	map_count = cb_count_lines(&game->file, 1);
	game->map = ft_calloc(sizeof(char *), map_count + 1);
	map_count = 0;
	if (fd == -1)
		return (1);
	while (cb_get_next_line(fd, &line))
	{
		map_count = cb_store_data(game, line, map_count);
		free(line);
	}
	free(line);
	close(fd);
	//testing
	// printf("%s", game->no);
	// printf("%s", game->so);
	// printf("%s", game->we);
	// printf("%s", game->ea);
	printf("%s", game->f);
	printf("%s", game->c);

	int j = 0;
	while (j < map_count)
	{
		printf("%s", game->map[j]);
		j++;
	}
	//end testing
	return (0);
}