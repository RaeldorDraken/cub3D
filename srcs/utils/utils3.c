/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:37:55 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/17 17:42:50 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

int	cb_check_colors_int(t_game *game)
{
	int	flag;

	flag = 0;
	if (game->c_clr[0] > 255 || game->c_clr[1] > 255 || game->c_clr[2] > 255)
		flag = 1;
	if (game->f_clr[0] > 255 || game->f_clr[1] > 255 || game->f_clr[2] > 255)
		flag = 1;
	if (game->c_clr[0] < 0 || game->c_clr[1] < 0 || game->c_clr[2] < 0)
		flag = 1;
	if (game->f_clr[0] < 0 || game->f_clr[1] < 0 || game->f_clr[2] < 0)
		flag = 1;
	if (flag)
		cb_print_msg("Error: Invalid colors\n", NULL);
	return (flag);
}

static int	cb_check_color2(char *str, int i, int flag)
{
	if (!str || str[i] == ',' || str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!ft_strchr("0123456789, \t", str[i]))
			return (1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (ft_strchr("0123456789", str[i]) && flag == 0)
			flag = 1;
		else if (flag == 1 && str[i] == ' ')
			flag = 2;
		else if (flag == 2 && ft_strchr("0123456789", str[i]))
			return (1);
		if (str[i] == ',')
			flag = 0;
		i++;
	}
	return (0);
}

int	cb_check_color(t_game *game)
{
	if (cb_check_color2(game->c, 0, 0) || cb_check_color2(game->f, 0, 0))
	{
		cb_print_msg("Error: Invalid color format\n", NULL);
		return (1);
	}
	game->c = cb_trim_colors(game->c);
	game->f = cb_trim_colors(game->f);
	return (0);
}
