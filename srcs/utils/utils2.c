/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:49:36 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/16 20:15:18 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

int	cb_count_lines(char **file, int count)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(*file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (cb_get_next_line(fd, &line))
	{
		i = cb_get_first_char(line, 0);
		if (line[i] == '1' || line[i] == '0')
			count++;
		free(line);
	}
	free(line);
	close(fd);
	return (count);
}

int	cb_count_lines2(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	cb_map_width(char **map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

int	cb_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

// int	cb_trim_colors(char *str)
// {

// 	return (0);
// }

int	cb_check_color(char *str, int i, int flag)
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
	return (0);//(cb_trim_colors(str));
}