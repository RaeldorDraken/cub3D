/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:28:20 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/17 17:58:45 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"



int	cb_get_player_x_ref(t_player *player, t_raycast *raycast)
{
	float	xcoord;
	
	if (raycast->side_ref == 0)
	{
		xcoord = (int)(player->pos.y + raycast->wdistpersp_ref * raycast->raydiry_ref) * 32;
	}
	else
	{
		xcoord = (int)(player->pos.x + raycast->wdistpersp_ref * raycast->raydirx_ref);
	}
	xcoord = xcoord - floor(xcoord);
	return ((int)xcoord * 32);
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

}

void	cb_find_hit(t_game *game)
{
	t_raycast	raycast;

	raycast = game->raycast;
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

void cb_paint_x(t_game *game)
{
	// draw_vertical(game, &rend, (int)(HEIGHT / rend.r.perpwalldist), compute_xcoord(&rend.pl, &rend.r));


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


	int		height;
	int		i;
	float	target; // ? pos_img
	float	cell;// ? step
	float 	xcoord;
	
	target = 0;
	height = (int)(HEIGHT / game->raycast.wdistpersp_ref);
	cell = (float)32 / height;
	i = 0;
	xcoord = cb_get_player_x_ref(&game->player, &game->raycast);
	
	

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
		//cb_put_px(&game->mlx.image, game->render_x, i, cb_get_hex_color(game->c_clr[0], game->c_clr[1], game->c_clr[2]));
		i++;
	}
	while (i < HEIGHT && i < (HEIGHT / 2 + height / 2))
	{
		//TODO paint walls
		

		cb_put_px(&game->mlx.image, game->render_x, i, cb_get_hex_color(255, 0, 0));
		//cb_put_px(&game->mlx.image, game->render_x, i, cb_get_my_pixel_form_texture(&game->walls[2], xcoord, (int)target));
		target += cell;
		++i;
	}
	while (i < HEIGHT)
	{
		//cb_put_px(&game->mlx.image, game->render_x, i, cb_get_hex_color(game->f_clr[0], game->f_clr[1], game->f_clr[2]));
		i++;
	}
}


int	cb_render(t_game *game)
{
	game->render_x = 0;
	while (game->render_x < WIDTH)
	{
		cb_set_render_vars(game);
		cb_find_dist_to_edge(game);
		cb_find_hit(game);
		game->raycast.wdistpersp_ref = cb_compute_dist(game);
		printf("%f\n", game->raycast.wdistpersp_ref);
		cb_paint_x(game);
		++game->render_x;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.image.img_ptr, 0, 0);
	return (0);
}
