/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:28:20 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/21 21:19:15 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

void	draw_vertical(t_game *game, t_render *rend, int height, int x_tex)
{
	int		i;
	float	step;
	float	pos_img;
	// t_image	*img;
	// t_image	*tex;

	//tex = &game->mlx.textures[choose_text(&rend->r)];
	//img = &game->mlx.img;
	(void)x_tex;
	i = 0;
	step = (float)64 / height;
	if (height >= HEIGHT)
		pos_img = step * (height - HEIGHT) / 2;
	else
		pos_img = 0;
	while (i < (HEIGHT / 2 - height / 2))
		cb_put_px(&game->mlx.image, rend->x, i++, cb_get_hex_color(game->c_clr[0], game->c_clr[1], game->c_clr[2]));
	while (i < HEIGHT && i < (HEIGHT / 2 + height / 2))
	{
		cb_put_px(&game->mlx.image, rend->x, i,
			cb_get_pixel_from_texture(
				&game->walls[cb_get_texture_num(&rend->r)],
				x_tex,
				(int)pos_img));
		pos_img += step;
		++i;
	}
	while (i < HEIGHT)
		cb_put_px(&game->mlx.image, rend->x, i++,
			cb_get_hex_color(game->f_clr[0], game->f_clr[1], game->f_clr[2]));
}

float	compute_dist(t_player *pl, t_raycast *r)
{
	if (r->side == 0)
		return ((r->mapx - pl->pos.x + (1 - r->stepx) / 2) / r->raydirx);
	else
		return ((r->mapy - pl->pos.y + (1 - r->stepy) / 2) / r->raydiry);
}

void	init_render_vars(t_player *pl, t_raycast *r, int x)
{
	r->camerax = 2 * x / (float)WIDTH - 1;
	r->raydirx = pl->dir.x + pl->plane.x * r->camerax;
	r->raydiry = pl->dir.y + pl->plane.y * r->camerax;
	r->mapx = pl->pos.x;
	r->mapy = pl->pos.y;
	r->deltadistx = fabs(1 / r->raydirx);
	r->deltadisty = fabs(1 / r->raydiry);
	r->hit = 0;
}

void	find_dist_to_edge(t_player *pl, t_raycast *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (pl->pos.x - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - pl->pos.x) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (pl->pos.y - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - pl->pos.y) * r->deltadisty;
	}
}

void	find_collision(t_game *game, t_raycast *r)
{
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if (game->map[r->mapx][r->mapy] == '1')
			r->hit = 1;
	}
}

int	cb_render(t_game *game)
{
	t_render	render;

	render.x = 0;
	render.pl = game->player;
	while (render.x < WIDTH)
	{
		init_render_vars(&render.pl, &render.r, render.x);
		find_dist_to_edge(&render.pl, &render.r);
		find_collision(game, &render.r);
		render.r.perpwalldist = compute_dist(&render.pl, &render.r);
		draw_vertical(game, &render, (int)(HEIGHT / render.r.perpwalldist), \
		compute_dist(&render.pl, &render.r));
		++render.x;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.image.img_ptr, 0, 0);
	return (0);
}
