/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:56:42 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/11 20:21:12 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include "../libs/mlx/mlx.h"
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
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			image;
}	t_window;

typedef struct s_game
{
	// char		*no;
	// char		*so;
	// char		*we;
	// char		*ea;
	char		*text_paths[MAX];
	char		*f;
	char		*c;
	int			f_clr[3];
	int			c_clr[3];
	t_image		walls[MAX];
	t_player	player;
	t_window	mlx;
	char		*file;
	char		**map;
}	t_game;

// * Get Next Line
// ? libs/gnl/get_next_line.c
char	*cb_get_next_line(int fd, char **line_out);

// * Parser
// ? srcs/parser/parser.c
int		cb_parser(t_game *game);

// * Setup
// ? src/setup/setup.c

int		cb_setup(t_game *game);
int		cb_load_textures(t_game *game, int index);

// * Utils
// ? srcs/utils/utils.c
int		cb_get_first_char(char *input, int i);
char	*cb_free_return_null(char *ptr);
char	*cb_strjoinchr(char *str, char ch);
void	cb_print_msg(char *str);

// * Validations
// ? srcs/validations/validations.c
int		cb_validate_args(int argc);
int		cb_validate_map_extension(char *map_str);