/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_helpers_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:07:33 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/21 21:20:27 by rabril-h         ###   ########.fr       */
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

int	cb_get_pixel_from_texture(t_image *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)pixel);
}

// int	ft_get_color_image(t_image img, t_int_vector text, int text_height)
// {
// 	return (*(int *)(img.pixels
// 		+ ((text_height * text.y + text.x) * (img.bits_per_pixel / 8))));
// }

// float	cb_compute_texture_dist(t_game *game)
// {
// 	if (game->raycast.side_ref == 0)
// 		return ((game->raycast.map_x_ref - game->player.pos.x
// 				+ (1 - game->raycast.step_x_ref) / 2)
// 			/ game->raycast.raydir_x_ref);
// 	else
// 		return ((game->raycast.map_y_ref - game->player.pos.y
// 				+ (1 - game->raycast.step_y_ref) / 2)
// 			/ game->raycast.raydir_y_ref);
// }

int	cb_get_texture_num(t_raycast *raycast)
{
	if (raycast->side == 0 && raycast->raydirx < 0)
		return (0);
	else if (raycast->side == 0 && raycast->raydirx > 0)
		return (1);
	else if (raycast->side == 1 && raycast->raydiry > 0)
		return (2);
	else
		return (3);
}

unsigned int	cb_get_hex_color(int r, int g, int b)
{
	return (
		((r & 0xff) << 16)
		+ ((g & 0xff) << 8)
		+ (b & 0xff)
	);
}