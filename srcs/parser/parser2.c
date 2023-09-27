/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:53:58 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/27 12:00:51 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

int	cb_squared_map(char **map)
{
	int	w;
	int	i;

	i = 0;
	if (!map)
		return (1);
	w = cb_map_width(map);
	while (map[i] != NULL)
	{
		while (ft_strlen(map[i]) < (size_t)w)
			map[i] = cb_strjoinchr(map[i], ' ');
		i++;
	}
	return (0);
}

void	cb_format_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == ' ')
				game->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	cb_store_current_line(t_game *game, char *input, int type, int i)
{
	if (type < 0)
	{
		if (type == -1 && game->f != NULL)
			cb_print_msg("Error: Duplicate key\n", "1");
		else if (type == -1)
			game->f = ft_substr(input, cb_start_path(input, i, 1),
					ft_strlen(input) - i);
		else if (type == -2 && game->c != NULL)
			cb_print_msg("Error: Duplicate key\n", "1");
		else if (type == -2)
			game->c = ft_substr(input, cb_start_path(input, i, 1),
					ft_strlen(input) - i);
		return (0);
	}
	if (game->text_paths[type] != NULL)
		cb_print_msg("Error: Duplicate key\n", "1");
	else
		game->text_paths[type] = ft_substr(input, cb_start_path(input, i, 0),
				ft_strlen(input) - i);
	return (0);
}
