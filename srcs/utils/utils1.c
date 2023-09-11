/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:19:21 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/11 15:02:55 by rabril-h         ###   ########.fr       */
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
