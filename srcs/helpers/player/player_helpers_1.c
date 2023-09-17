/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_helpers_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:02:04 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/16 17:48:26 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cube.h"

void	cb_parse_dir_north(t_player *player)
{
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
}

void	cb_parse_dir_south(t_player *player)
{
	player->dir.x = 1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = -0.66;
}

void	cb_parse_dir_east(t_player *player)
{
	player->dir.x = 0;
	player->dir.y = 1;
	player->plane.x = 0.66;
	player->plane.y = 0;
}

void	cb_parse_dir_west(t_player *player)
{
	player->dir.x = 0;
	player->dir.y = -1;
	player->plane.x = -0.66;
	player->plane.y = 0;
}
