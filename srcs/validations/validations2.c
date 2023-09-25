/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:54:11 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/25 21:10:09 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

int	cb_initialize_file_values(t_game *game)
{
	int	i;

	i = 0;
	game->f = NULL;
	game->c = NULL;
	while (i < MAX)
		game->text_paths[i ++] = NULL;
	game->map = NULL;
	i = 0;
	while (i < 3)
	{
		game->c_clr[i] = -1;
		game->f_clr[i ++] = -1;
	}
	return (0);
}

int	cb_validate_values(t_game *game)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (game->f == NULL || game->c == NULL)
		flag = 1;
	while (i < MAX)
	{
		if (game->text_paths[i] == NULL)
			flag = 2;
		i ++;
	}
	if (game->map == NULL)
		flag = 3;
	i = 0;
	while (i < 3)
	{
		if (game->c_clr[i] == -1 || game->f_clr[i] == -1)
			flag = 4;
		i ++;
	}
	if (flag)
		cb_print_msg("Error: Missing values\n", NULL);
	return (flag);
}

int	cb_check_incorrect_keys(t_game *game)
{
	(void)game;
	return (0);
}

int	cb_key_error(t_game *game)
{
	(void)game;
	cb_print_msg("Error: misconfigured keys\n", NULL);
	return (1);
}