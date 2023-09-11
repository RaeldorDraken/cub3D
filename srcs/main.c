/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:10:08 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/11 15:14:48 by rabril-h         ###   ########.fr       */
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
	return (0);
}