/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:38:23 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/14 21:18:48 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

int	cb_validate_args(int argc)
{
	if (argc != 2)
	{
		cb_print_msg("Error: Invalid number of arguments\n", NULL);
		cb_print_msg("Usage: ./cub3d <map.cub>\n", NULL);
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
		cb_print_msg("Error: Invalid map extension\n", NULL);
		cb_print_msg("Usage: ./cub3d <map.cub>\n", NULL);
		return (1);
	}
	return (0);
}

int	cb_validate_map_chars(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(" 01NSEW", map[i][j]))
				flag = 2;
			else if (ft_strchr("NSEW", map[i][j]))
				flag++;
			j++;
		}
		i++;
	}
	if (flag > 1)
	{
		cb_print_msg("Error: Invalid map\n", NULL);
		return (1);
	}
	return (0);
}

static int	cb_check_space_sides(char **map, int i, int j)
{
	(void) map;
	(void) i;
	(void) j;
	// if (map[i + 1] != NULL)
	// {
	// 	if (map[i][j + 1] == '0' || map[i][j - 1] == '0')
	// 		return (1);
	// 	else if (map[i + 1][j] == '0')
	// 		return (1);
	// }
	// else
	// {
	// 	if (map[i][j + 1] == '0' || map[i][j - 1] == '0')
	// 		return (1);
	// 	else if (map[i - 1][j] == '0')
	// 		return (1);
	// }
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
			if (((i == cb_count_lines2(map) - 1 || i == 0)
					&& map[i][j] != '1' && map[i][j] != ' ')
				|| ((map[i][j] == ' ' && cb_check_space_sides(map, i, j))
				|| map[i][0] == '0' || map[i][ft_strlen(map[i]) - 1] == '0'))
			{
				cb_print_msg("Error: Invalid map\n", NULL);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}