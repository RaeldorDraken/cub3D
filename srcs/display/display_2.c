/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:24:51 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/25 20:45:34 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

int	cb_compute_xcoord(t_player *pl, t_raycast *rc)
{
	float	xcoord;

	if (rc->side == 0)
		xcoord = pl->pos.y + rc->perpwalldist * rc->raydiry;
	else
		xcoord = pl->pos.x + rc->perpwalldist * rc->raydirx;
	xcoord = xcoord - floor(xcoord);
	return ((int)(xcoord * pl->text_size));
}

float	cb_compute_dist(t_player *pl, t_raycast *rc)
{
	if (rc->side == 0)
		return ((rc->mapx - pl->pos.x + (1 - rc->stepx) / 2) / rc->raydirx);
	else
		return ((rc->mapy - pl->pos.y + (1 - rc->stepy) / 2) / rc->raydiry);
}

void	cb_set_render_vars(t_player *pl, t_raycast *rc, int x)
{
	rc->camerax = 2 * x / (float)WIDTH - 1;
	rc->raydirx = pl->dir.x + pl->plane.x * rc->camerax;
	rc->raydiry = pl->dir.y + pl->plane.y * rc->camerax;
	rc->mapx = pl->pos.x;
	rc->mapy = pl->pos.y;
	rc->deltadistx = fabs(1 / rc->raydirx);
	rc->deltadisty = fabs(1 / rc->raydiry);
	rc->hit = 0;
}

void	cb_find_dist_to_edge(t_player *pl, t_raycast *rc)
{
	if (rc->raydirx < 0)
	{
		rc->stepx = -1;
		rc->sidedistx = (pl->pos.x - rc->mapx) * rc->deltadistx;
	}
	else
	{
		rc->stepx = 1;
		rc->sidedistx = (rc->mapx + 1.0 - pl->pos.x) * rc->deltadistx;
	}
	if (rc->raydiry < 0)
	{
		rc->stepy = -1;
		rc->sidedisty = (pl->pos.y - rc->mapy) * rc->deltadisty;
	}
	else
	{
		rc->stepy = 1;
		rc->sidedisty = (rc->mapy + 1.0 - pl->pos.y) * rc->deltadisty;
	}
}

void	cb_find_collision(t_game *game, t_raycast *rc)
{
	while (rc->hit == 0)
	{
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->stepx;
			rc->side = 0;
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->stepy;
			rc->side = 1;
		}
		if (game->map[rc->mapx][rc->mapy] == '1')
			rc->hit = 1;
	}
}
