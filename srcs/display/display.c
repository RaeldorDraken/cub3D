/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:28:20 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/25 20:14:32 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

void	cb_paint_x(t_game *game, t_render *rend, int height, int x_tex)
{
	int		i;
	float	step;
	float	pos_img;

	i = 0;
	step = (float)TEXT_SIZE / height;
	if (height >= HEIGHT)
		pos_img = step * (height - HEIGHT) / 2;
	else
		pos_img = 0;
	while (i < (HEIGHT / 2 - height / 2))
		cb_put_px(&game->mlx.image, rend->x, i++,
			cb_get_hex_color(game->c_clr[0], game->c_clr[1], game->c_clr[2]));
	while (i < HEIGHT && i < (HEIGHT / 2 + height / 2))
	{
		cb_put_px(&game->mlx.image, rend->x, i,
			cb_get_pixel_from_texture(
				&game->walls[cb_get_texture_num(&rend->rc)],
				x_tex, (int)pos_img));
		pos_img += step;
		++i;
	}
	while (i < HEIGHT)
		cb_put_px(&game->mlx.image, rend->x, i++,
			cb_get_hex_color(game->f_clr[0], game->f_clr[1], game->f_clr[2]));
}

int	cb_render(t_game *game)
{
	t_render	render;

	render.x = 0;
	render.pl = game->player;
	while (render.x < WIDTH)
	{
		cb_set_render_vars(&render.pl, &render.rc, render.x);
		cb_find_dist_to_edge(&render.pl, &render.rc);
		cb_find_collision(game, &render.rc);
		render.rc.perpwalldist = cb_compute_dist(&render.pl, &render.rc);
		cb_paint_x(game, &render, (int)(HEIGHT / render.rc.perpwalldist), \
		cb_compute_xcoord(&render.pl, &render.rc));
		++render.x;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.image.img_ptr, 0, 0);
	return (0);
}
