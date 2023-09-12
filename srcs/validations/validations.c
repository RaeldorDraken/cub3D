/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:38:23 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/12 21:18:26 by eros-gir         ###   ########.fr       */
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

int	cb_validate_map_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(" 01NSEW", map[i][j]))
			{
				cb_print_msg("Error: Invalid map\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	cb_check_space_sides(char **map, int i, int j)
{
	if (map[i][j + 1] == '\0' || j == 0)
		return (0);
	else if (i == 0)
	{
		if (map[i][j + 1] == '0' || map[i][j - 1] == '0')
			return (1);
		else if (map[i + 1][j] == '0')
			return (1);
	}
	else if (map[i + 1] == NULL)
	{
		if (map[i][j + 1] == '0' || map[i][j - 1] == '0')
			return (1);
		else if (map[i - 1][j] == '0')
			return (1);
	}
	return (0);
}

int	cb_check_map_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i + 1] == NULL && map[i][j] == '0')
				|| (ft_strlen(map[i + 1]) < (size_t)j && map[i][j] == '0'))
			{
				cb_print_msg("Error: Invalid map\n");
				return (1);
			}
			if ((map[i][j] == ' ' && cb_check_space_sides(map, i, j))
				|| map[i][0] == '0' || map[i][ft_strlen(map[i]) - 1] == '0')
			{
				cb_print_msg("Error: Invalid map\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}