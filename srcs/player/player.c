/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:57:49 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/20 20:56:22 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

void	cb_parse_player_dir(t_player *player, char pos)
{
	printf("pos is %c", pos);
	if (pos == 'N')
		cb_parse_dir_north(player);
	if (pos == 'S')
		cb_parse_dir_south(player);
	if (pos == 'W')
		cb_parse_dir_west(player);
	if (pos == 'E')
		cb_parse_dir_east(player);
}

void	cb_player_dir(t_game *game)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (game->map[c1])
	{
		c2 = 0;
		while (game->map[c1][c2])
		{
			if (game->map[c1][c2] == 'N' || game->map[c1][c2] == 'S' ||
			game->map[c1][c2] == 'E' || game->map[c1][c2] == 'W')
				cb_parse_player_dir(&game->player, game->map[c1][c2]);
			c2++;
		}
		c1++;
	}
}

t_pos	cb_get_player_pos(t_game *game)
{
	t_pos	pos;
	int		c1;
	int		c2;

	c1 = 0;
	c2 = 0;
	while (game->map[c1])
	{
		c2 = 0;
		while (game->map[c1][c2])
		{
			if (game->map[c1][c2] == 'N' || game->map[c1][c2] == 'S' ||
			game->map[c1][c2] == 'E' || game->map[c1][c2] == 'W')
			{
				pos.y = c2 + 0.5;
				pos.x = c1 + 0.5;
				break ;
			}
			c2++;
		}
		c1++;
	}
	return (pos);
}