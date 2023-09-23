/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_helpers_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:39:08 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/23 22:14:10 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cube.h"

double	cb_get_player_new_position(double dir)
{
	return (dir * SPEED);
}

t_pos	cb_get_player_new_rotation(float dir_x, float dir_y, float rot_speed)
{
	t_pos	dir;

	dir.x = dir_x * cos(rot_speed) - dir_y * sin(rot_speed);
	dir.y = dir_x * sin(rot_speed) + dir_y * cos(rot_speed);
	return (dir);
}

int	cb_player_can_move(char **map, double pos_x, double pos_y)
{
	if (map[(int)trunc(pos_x)][(int)trunc(pos_y)] != '1'
		&& map[(int)trunc(pos_x + COL_BUFF)][(int)trunc(pos_y + COL_BUFF)] != '1'
		&& map[(int)trunc(pos_x - COL_BUFF)][(int)trunc(pos_y - COL_BUFF)] != '1'
		&& map[(int)trunc(pos_x - COL_BUFF)][(int)trunc(pos_y + COL_BUFF)] != '1'
		&& map[(int)trunc(pos_x + COL_BUFF)][(int)trunc(pos_y - COL_BUFF)] != '1'
		)
		return (1);
	return (0);
}