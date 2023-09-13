/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:09:06 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/13 20:24:09 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

static int	cb_start_path(char *input, int i, int type)
{
	if (type == 0)
	{
		while (input[i] != '.')
			i++;
	}
	else
	{
		while (!ft_isdigit(input[i]))
			i++;
	}
	return (i);
}

static void	cb_get_color(t_game *game, int i, int j, int type)
{
	int	color;

	while (j < 3)
	{
		color = 0;
		if (type == 0)
		{
			while (game->c[i] != ',' && game->c[i] != '\0')
				color = color * 10 + (game->c[i ++] - '0');
			game->c_clr[j] = color;
		}
		else if (type == 1)
		{
			while (game->f[i] != ',' && game->f[i] != '\0')
				color = color * 10 + (game->f[i ++] - '0');
			game->f_clr[j] = color;
		}
		j ++;
		i ++;
	}
}

static int	cb_store_data(t_game *game, char *input, int map_count)
{
	int	i;

	i = cb_get_first_char(input, 0);
	if (input[i] == 'N')
		game->text_paths[NORTH] = ft_substr(input, cb_start_path(input, i, 0),
				ft_strlen(input) - i);
	else if (input[i] == 'S')
		game->text_paths[SOUTH] = ft_substr(input, cb_start_path(input, i, 0),
				ft_strlen(input) - i);
	else if (input[i] == 'W')
		game->text_paths[WEST] = ft_substr(input, cb_start_path(input, i, 0),
				ft_strlen(input) - i);
	else if (input[i] == 'E')
		game->text_paths[EAST] = ft_substr(input, cb_start_path(input, i, 0),
				ft_strlen(input) - i);
	else if (input[i] == 'F')
		game->f = ft_substr(input, cb_start_path(input, i, 1),
				ft_strlen(input) - i);
	else if (input[i] == 'C')
		game->c = ft_substr(input, cb_start_path(input, i, 1),
				ft_strlen(input) - i);
	else if (input[i] == '1' || input[i] == '0')
		game->map[map_count++] = ft_substr(input, 0, ft_strlen(input));
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

static void cb_squared_map(char **map)
{
	int	w;
	int	i;

	i = 0;
	w = cb_map_width(map);
	while (map[i] != NULL)
	{
		while (ft_strlen(map[i]) < (size_t)w)
			map[i] = cb_strjoinchr(map[i], ' ');
		i++;
	}
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
	cb_get_color(game, 0, 0, 0);
	cb_get_color(game, 0, 0, 1);
	cb_squared_map(game->map);
	free(line);
	close(fd);
	if (cb_validate_map_chars(game->map) || cb_check_map_walls(game->map))
		return (1);
	//testing
			 int j = 0;
			// while (j < MAX)
			// {
			// 	printf("Line_%d: '%s'\n", j, game->text_paths[j]);
			// 	j++;
			// }
			// j = 0;
			// while (j < 3)
			// {
			// 	printf("fColor_%d: '%d'\n", j, game->f_clr[j]);
			// 	j++;
			// }
			// j = 0;
			// while (j < 3)
			// {
			// 	printf("cColor_%d: '%d'\n", j, game->c_clr[j]);
			// 	j++;
			// }
			// j = 0;
			while (j < map_count)
			{
				printf("'%s'\n", game->map[j]);
				j++;
			}
	//end testing
	return (0);
}