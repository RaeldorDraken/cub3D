/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:10:34 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/13 15:57:07 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../incl/cube.h"

int	cb_destroy(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	//free(game->map);
	//free(game->text_paths);
	if (game->mlx.win_ptr && game->mlx.mlx_ptr)
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	exit(0);
}
