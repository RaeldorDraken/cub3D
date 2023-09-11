/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:38:23 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/11 20:14:09 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

int	cb_validate_args(int argc)
{
	if (argc != 2)
	{
		cb_print_msg("Error: Invalid number of arguments\n");
		cb_print_msg("Usage: ./cub3d <map.cub>\n");
		return (1);
	}
	return (0);
}

int	cb_validate_map_extension(char *map_str)
{
	int	len;

	len = ft_strlen(map_str);
	if (len < 4 || !ft_strnstr(&map_str[len - 4], ".cub", 4))
	{
		cb_print_msg("Error: Invalid map extension\n");
		cb_print_msg("Usage: ./cub3d <map.cub>\n");
		return (1);
	}
	return (0);
}
