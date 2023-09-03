/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:56:42 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/03 19:36:00 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include "../libs/libft/libft.h"

#define WIDTH 800
#define HEIGHT 600

enum e_tx {
	NORTH,
	SOUTH,
	WEST,
	EAST,
	MAX
};

typedef struct s_image {
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_player {
	double	x;
	double	y;
	double	dir;
	double	fov;
}	t_player;

typedef struct s_window {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_window;

typedef struct s_game
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
	t_image		walls[MAX];
	t_player	player;

	char		**map;
}	t_game;