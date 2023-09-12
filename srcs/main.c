/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:10:08 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/12 22:27:14 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cube.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (cb_validate_args(argc) || cb_validate_map_extension(argv[1]))
		return (1);
	game.file = argv[1];
	cb_parser(&game);
	cb_setup(&game);

	// TODO temporary loop
	mlx_key_hook(game.mlx.win_ptr, &cb_key_hook, &game.mlx); // TODO temporary hook for getting keys
	mlx_hook(game.mlx.win_ptr, 17, 0, &cb_destroy, &game); // ? Exits on window red button click

	// TODO render loop
	//TODO render(&game);
	//TODO mlx_loop_hook(game.mlx.mlx, render, &game);

	mlx_loop(game.mlx.mlx_ptr); // ? Main loop
	return (0);
}