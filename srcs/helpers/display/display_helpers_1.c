/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_helpers_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:07:33 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/17 17:45:46 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cube.h"

void	cb_put_px(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

int	cb_get_my_pixel_form_texture(t_image *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)pixel);
}

float	cb_compute_dist(t_game *game)
{
	if (game->raycast.side_ref == 0)
		return ((game->raycast.mapx_ref - game->player.pos.x
				+ (1 - game->raycast.stepx_ref) / 2)
			/ game->raycast.raydirx_ref);
	else
		return ((game->raycast.mapy_ref - game->player.pos.y
				+ (1 - game->raycast.stepy_ref) / 2)
			/ game->raycast.raydiry_ref);
}

unsigned int	cb_get_hex_color(int r, int g, int b)
{
	return (
		((r & 0xff) << 16)
		+ ((g & 0xff) << 8)
		+ (b & 0xff)
	);
}