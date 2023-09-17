/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:53:58 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/17 17:55:40 by eros-gir         ###   ########.fr       */
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
