/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:28:20 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/14 20:37:20 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

void	cb_put_px(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	cb_render(t_game *game)
{
	// cb_print_msg("Loop", NULL);
	
	int w;
	int h;
	
	w = 0;
	h = 0;

	while (w < WIDTH)
	{
		h = 0;		
		while (h < HEIGHT / 2.65)
		{
			cb_put_px(&game->mlx.image, w, h, cb_get_hex_color(game->c_clr[0], game->c_clr[1], game->c_clr[2]));
			h++;
		}
		w++;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.image.img_ptr, 0, 0);
	return (0);
}