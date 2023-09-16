/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:28:20 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/16 20:09:15 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

void cb_paint_x(t_game *game)
{
	
	int		height;
	int		i;
	float	target;
	float	cell;

	height = HEIGHT / (int)game->raycast.wdistpersp_ref;
	cell = (float)32 / height;
	i = 0;
	
	if (height >= HEIGHT)
	{
		target = cell * (height - HEIGHT) / 2;
	}
	else
	{
		target = 0;
	}
	while (i < (HEIGHT / 2 - height / 2))
	{
		cb_put_px(&game->mlx.image, game->render_x, i++, cb_get_hex_color(game->c_clr[0], game->c_clr[1], game->c_clr[2]));
	}
	while (i < HEIGHT && i < (HEIGHT / 2 + height / 2))
	{
		//TODO paint walls
		target += cell;
		i++;
	}
	while (i < HEIGHT)
	{
		cb_put_px(&game->mlx.image, game->render_x, i++, cb_get_hex_color(game->f_clr[0], game->f_clr[1], game->f_clr[2]));
	}

	
	// int		i;
	// float	step;
	// float	pos_img;
	// t_image	*img;
	// t_image	*tex;

	// tex = &game->mlx.textures[choose_text(&rend->r)];
	// img = &game->mlx.img;
	// i = 0;
	// step = (float)64 / height;
	// if (height >= HEIGHT)
	// 	pos_img = step * (height - HEIGHT) / 2;
	// else
	// 	pos_img = 0;
	// while (i < (HEIGHT / 2 - height / 2))
	// 	my_pixel_put(img, rend->x, i++, c2int(&game->map.ceiling));
	// while (i < HEIGHT && i < (HEIGHT / 2 + height / 2))
	// {
	// 	my_pixel_put(img, rend->x, i, my_pixel_get(tex, x_tex, (int)pos_img));
	// 	pos_img += step;
	// 	++i;
	// }
	// while (i < HEIGHT)
	// 	my_pixel_put(img, rend->x, i++, c2int(&game->map.floor));
}



void	cb_set_render_vars(t_game *game)
{
	// ? x-coordinate in camera space
	
	game->raycast.camerax_ref = 2 * game->render_x / (float)WIDTH - 1;

	// ? set direction of ray on x based on player direction x	
	game->raycast.raydirx_ref = game->player.dir.x + game->player.plane.x * game->raycast.camerax_ref; 
	
	// ?  set direction of ray on based on player dir y
	game->raycast.raydiry_ref = game->player.dir.y + game->player.plane.y * game->raycast.camerax_ref; 

	 // ? set map x coordinates based on player location on x	
	game->raycast.mapx_ref = game->player.plane.x * game->raycast.camerax_ref;

	// ? set map y coordinates based on player location on y
	
	game->raycast.mapy_ref = game->player.plane.y * game->raycast.camerax_ref; 

	// ? set deltadist x based on x direction of ray on x
	
	game->raycast.deltadistx_ref = fabs(1 / game->raycast.raydirx_ref); 

	// ? set deltadist y based on x direction of ray on y
	
	game->raycast.deltadisty_ref = fabs(1 / game->raycast.raydiry_ref); 

	// ? reset walls hit point
	game->raycast.hit_ref = 0;


	

	// r->camerax = 2 * x / (float)WIDTH - 1;
	// r->raydirx = pl->dirx + pl->planex * r->camerax;
	// r->raydiry = pl->diry + pl->planey * r->camerax;
	// r->mapx = pl->locx;
	// r->mapy = pl->locy;
	// r->deltadistx = fabs(1 / r->raydirx);
	// r->deltadisty = fabs(1 / r->raydiry);
	// r->hit = 0;
}

void	cb_find_dist_to_edge(t_game *game)
{
	t_player	player;
	t_raycast	raycast;

	player = game->player;
	raycast = game->raycast;

	if (raycast.raydirx_ref < 0)
	{
		raycast.stepx_ref = -1;
		raycast.sidedistx_ref = (player.pos.x - raycast.mapx_ref) * raycast.deltadistx_ref;
	}
	else
	{
		raycast.stepx_ref = 1;
		raycast.sidedistx_ref = (raycast.mapx_ref + 1.0 - player.pos.x) * raycast.deltadistx_ref;
	}

	if (raycast.raydiry_ref < 0)
	{
		raycast.stepy_ref = -1;
		raycast.sidedisty_ref = (player.pos.y - raycast.mapy_ref) * raycast.deltadisty_ref;
	}
	else
	{
		raycast.stepy_ref = 1;
		raycast.sidedisty_ref = (raycast.mapy_ref + 1.0 - player.pos.y) * raycast.deltadisty_ref;
	}

	// if (r->raydirx < 0)
	// {
	// 	r->stepx = -1;
	// 	r->sidedistx = (pl->locx - r->mapx) * r->deltadistx;
	// }
	// else
	// {
	// 	r->stepx = 1;
	// 	r->sidedistx = (r->mapx + 1.0 - pl->locx) * r->deltadistx;
	// }


	// if (r->raydiry < 0)
	// {
	// 	r->stepy = -1;
	// 	r->sidedisty = (pl->locy - r->mapy) * r->deltadisty;
	// }
	// else
	// {
	// 	r->stepy = 1;
	// 	r->sidedisty = (r->mapy + 1.0 - pl->locy) * r->deltadisty;
	// }
	// return (SUCCESS);
}

void	cb_find_hit(t_game *game)
{
	t_raycast	raycast;

	raycast = game->raycast;

	// while (r->hit == 0)
	// {
	// 	if (r->sidedistx < r->sidedisty)
	// 	{
	// 		r->sidedistx += r->deltadistx;
	// 		r->mapx += r->stepx;
	// 		r->side = 0;
	// 	}
	// 	else
	// 	{
	// 		r->sidedisty += r->deltadisty;
	// 		r->mapy += r->stepy;
	// 		r->side = 1;
	// 	}
	// 	if (game->map.map[r->mapx][r->mapy] == '1')
	// 		r->hit = 1;
	// }
	
	while (raycast.hit_ref == 0)
	{
		if (raycast.sidedistx_ref < raycast.sidedisty_ref)
		{
			raycast.sidedistx_ref += raycast.deltadistx_ref;
			raycast.mapx_ref += raycast.stepx_ref;
			raycast.side_ref = 0;
		}
		else
		{
			raycast.sidedisty_ref += raycast.deltadisty_ref;
			raycast.mapy_ref += raycast.stepy_ref;
			raycast.side_ref = 1;
		}
		if (game->map[raycast.mapx_ref][raycast.mapy_ref] == '1')
			raycast.hit_ref = 1;
	}

}

int	cb_render(t_game *game)
{
	float	xcoord;
	
	game->render_x = 0;
	
	
	while (game->render_x < WIDTH)
	{
		
		cb_set_render_vars(game);
		cb_find_dist_to_edge(game);

		// TODO function compute distance

		if (game->raycast.side_ref == 0)
		{

			game->raycast.wdistpersp_ref = ((game->raycast.mapx_ref - game->player.pos.x + (1 - game->raycast.stepx_ref) / 2) / game->raycast.raydirx_ref);
		}
		else
		{
			game->raycast.wdistpersp_ref = ((game->raycast.mapy_ref - game->player.pos.y + (1 - game->raycast.stepy_ref) / 2) / game->raycast.raydiry_ref);
		}
		
		cb_paint_x(game);
		// while (h < HEIGHT / 2)
		// {
		// 	cb_put_px(&game->mlx.image, w, h, cb_get_hex_color(game->c_clr[0], game->c_clr[1], game->c_clr[2]));
		// 	h++;
		// }		
		// while (h < HEIGHT)
		// {
		// 	cb_put_px(&game->mlx.image, w, h, cb_get_hex_color(game->f_clr[0], game->f_clr[1], game->f_clr[2]));
		// 	h++;
		// }
		
		// w++;		

		if (game->raycast.side_ref == 0)
		{
			xcoord = (int)(game->player.pos.y + game->raycast.wdistpersp_ref * game->raycast.raydiry_ref) * 32;
		}
		else
		{
			xcoord = (int)(game->player.pos.x + game->raycast.wdistpersp_ref * game->raycast.raydirx_ref);
		}
		xcoord = xcoord - floor(xcoord);
		game->render_x++;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.image.img_ptr, 0, 0);
	return (0);
}
