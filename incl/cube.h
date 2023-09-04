/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:56:42 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/04 18:18:46 by eros-gir         ###   ########.fr       */
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
	char		*f;
	char		*c;
	int			f_clr[3];
	int			c_clr[3];
	t_image		walls[MAX];
	t_player	player;
	char		*file;
	char		**map;
}	t_game;

// libs/gnl/get_next_line.c
char	*cb_get_next_line(int fd, char **line_out);

// srcs/parser/parser.c
int		cb_parser(t_game *game);

// srcs/utils/utils.c
int		cb_get_first_char(char *input, int i);
char	*cb_free_return_null(char *ptr);
char	*cb_strjoinchr(char *str, char ch);