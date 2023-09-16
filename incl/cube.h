/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:56:42 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/16 19:48:49 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include "../libs/mlx/mlx.h"
#include "../libs/libft/libft.h"

#define WIDTH 800
#define HEIGHT 640
#define SPEED 0.06
#define ROT_SPEED 0.02
#define PI 3.14159265359
#define CAMERA 400

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

typedef struct s_keys {
	int	forward;
	int	backward;
	int	left;
	int	right;
	int	pan_left;
	int	pan_right;
}	t_keys;

typedef struct s_pos {
	float	x;
	float	y;
}	t_pos;

typedef struct s_player {
	t_pos	pos; // ? lock x and lock y
	t_pos	dir; // ? dir x and dir y
	float	fov; // ? angle
	t_pos	plane; // ? plane x and plane y
	t_keys	keys;
}	t_player;

typedef struct s_window {
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			image;
}	t_window;

typedef struct raycast {
	float		camerax_ref; // ? camerax;
	int			mapx_ref; // ? mapx;
	int			mapy_ref; // ? mapy;
	int			stepx_ref; // ? stepx;
	int			stepy_ref; // ? stepy;
	int			hit_ref; // ? hit;
	int			side_ref; // ? side;
	float		sidedistx_ref; // ? sidedistx;
	float		sidedisty_ref; // ? sidedisty
	float		deltadistx_ref; // ? deltadistx;
	float		deltadisty_ref; // ? deltadisty;
	float		raydirx_ref; // ? raydirx;
	float		raydiry_ref; // ? radydiry;
	float		wdistpersp_ref; // ? perpwalldist;
}	t_raycast;


typedef struct s_game {
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
	int			render_x; // ? x
	t_raycast	raycast; // ? r
}	t_game;

// * Get Next Line
// ? libs/gnl/get_next_line.c
char			*cb_get_next_line(int fd, char **line_out);

// * Parser
// ? srcs/parser/parser.c
int				cb_parser(t_game *game);

// * Setup
// ? src/setup/setup.c

int				cb_setup(t_game *game);
int				cb_load_textures(t_game *game, int index);
int				cb_init_keys(t_game *game);
int				cb_init_player(t_game *game);

// * Interactive
// ? srcs/interactive/interactive.c

int				cb_keydown(int key, t_game *game);
int				cb_keyup(int key, t_game *game);

// * Display
// ? srcs/display/display.c
int				cb_render(t_game *game);
void			cb_set_render_vars(t_game *game);
void			cb_find_dist_to_edge(t_game *game);
void			cb_paint_x(t_game *game);

// * Player
// ? srcs/player/player.c
t_pos			cb_get_player_pos(t_game *game);
void			cb_player_dir(t_game *game);
void			cb_parse_player_dir(t_player *player, char pos);


// * Helpers
// ? srcs/helpers/player/player_helpers_1.c
void			cb_parse_dir_north(t_player *player);
void			cb_parse_dir_south(t_player *player);
void			cb_parse_dir_west(t_player *player);
void			cb_parse_dir_east(t_player *player);

// ? srcs/helpers/display/display_helpers_1.c
unsigned int	cb_get_hex_color(int r, int g, int b);
void			cb_put_px(t_image *data, int x, int y, int color);

// * Utils
// ? srcs/utils/utils.c
int				cb_get_first_char(char *input, int i);
char			*cb_free_return_null(char *ptr);
char			*cb_strjoinchr(char *str, char ch);
void			cb_print_msg(char *str, char *exit_code);
int				cb_count_lines2(char **arr);
int				cb_map_width(char **map);
int				cb_map_height(char **map);

// * Validations
// ? srcs/validations/validations.c
int				cb_validate_args(int argc);
int				cb_validate_map_extension(char *map_str);


// * Destroy
// ? srcs/validations/destroy.c
int				cb_destroy(t_game *game);
int				cb_validate_map_chars(char **map);
int				cb_check_map_walls(char **map);
