/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:19:21 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:47 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

int		cb_get_first_char(char *input, int i)
{
	while (ft_strchr(input + i, ' '))
	{
		if (input[i] == ' ')
			i++;
		else
			return (i);
	}
	return (i);
}

char	*cb_free_return_null(char *ptr)
{
	free(ptr);
	return (NULL);
}

char	*cb_strjoinchr(char *str, char ch)
{
	char	*copy;
	int		c;

	c = -0;
	if (str == NULL)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	copy = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	if (!copy)
		return (cb_free_return_null(copy));
	while (str[c])
	{
		copy[c] = str[c];
		c++;
	}
	copy[c] = ch;
	copy[c + 1] = '\0';
	free(str);
	return (copy);
}

void	cb_print_msg(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	cb_count_lines2(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int cb_map_width(char **map)
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