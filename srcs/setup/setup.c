/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:51:20 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/11 20:23:17 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"


int	cb_load_textures(t_game *game, int index)
{
	int width;
	int height;


	game->walls[index].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->text_paths[index], &width, &height);
	if (!game->walls[index].img_ptr)
		cb_print_msg("Error: Could not load image");
	game->walls[index].addr
		= mlx_get_data_addr(game->walls[index].img_ptr,
			&game->walls[index].bpp, &game->walls[index].line_len,
			&game->walls[index].endian);
	if (!game->walls[index].addr)
		cb_print_msg("Error loading image \n");
	return (0);
}

int	cb_setup(t_game *game)
{
	int i;

	i = -1;
	game->mlx.mlx_ptr = mlx_init();
	// TODO poner safes
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr,
			WIDTH, HEIGHT,
			"Cub3D");
	game->mlx.image.img_ptr = mlx_new_image(game->mlx.mlx_ptr, WIDTH, HEIGHT);
	game->mlx.image.addr = mlx_get_data_addr(game->mlx.image.img_ptr,
			&(game->mlx.image.bpp),
			&(game->mlx.image.line_len), &(game->mlx.image.endian));
	while (++i < 4)
		cb_load_textures(game, i);
	return (0);
}
