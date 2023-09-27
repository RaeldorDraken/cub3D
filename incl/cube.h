/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:56:42 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/27 22:19:18 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include "../libs/mlx/mlx.h"
#include "../libs/libft/libft.h"

#define WIDTH 800
#define HEIGHT 640
#define SPEED 0.5 // ? 0.06
#define ROT_SPEED 0.08 // ? 0.02
#define PI 3.14159265359
#define COL_BUFF 0.25
#define TEXT_SIZE 32

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
	t_pos	pos;
	t_pos	dir;
	t_pos	plane;
	t_keys	keys;
	int		player;
	int		text_size;
}	t_player;

typedef struct s_window {
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			image;
}	t_window;

typedef struct raycast {
	float		camerax;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	float		sidedistx;
	float		sidedisty;
	float		deltadistx;
	float		deltadisty;
	float		raydirx;
	float		raydiry;
	float		perpwalldist;
}	t_raycast;

typedef struct s_render
{
	int			x;
	t_player	pl;
	t_raycast	rc;
}	t_render;

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
	t_render	render;
	int			text_size;
}	t_game;

// * Get Next Line
// ? libs/gnl/get_next_line.c
char			*cb_get_next_line(int fd, char **line_out);

// * Parser
// ? srcs/parser/parser.c
int				cb_parser(t_game *game);
int				cb_start_path(char *input, int i, int type);

// ? srcs/parser/parser2.c
int				cb_squared_map(char **map);
void			cb_format_map(t_game *game);
int				cb_store_current_line(t_game *game, char *input, int type, int i);
int				cb_check_dup_textures(t_game *game);

// * Setup
// ? src/setup/setup.c

int				cb_setup(t_game *game);
int				cb_load_textures(t_game *game, int index);
int				cb_init_player(t_game *game);

// * Interactive
// ? srcs/interactive/interactive.c

int				cb_keydown(int key, t_game *game);
void			cb_move_left(t_game *game);
void			cb_move_right(t_game *game);
int				cb_compute_xcoord(t_player *pl, t_raycast *r);
void			cb_move_forward(t_game *game);
void			cb_move_backward(t_game *game);

// * Display
// ? srcs/display/display.c
int				cb_render(t_game *game);
void			cb_set_render_vars(t_player *pl, t_raycast *rc, int x);
void			cb_find_dist_to_edge(t_player *pl, t_raycast *rc);
void			cb_find_collision(t_game *game, t_raycast *rc);
float			cb_compute_dist(t_player *pl, t_raycast *rc);
void			cb_paint_x(t_game *game, t_render *rend, int height, int x_tex);

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
int				cb_get_pixel_from_texture(t_image *img, int x, int y);
float			cb_compute_texture_dist(t_game *game);
int				cb_get_texture_num(t_raycast *raycast);

// ? srcs/helpers/interactive/interactive_helpers_1.c

t_pos			cb_get_player_new_rotation(float dir_x,
					float dir_y, float rot_speed);
int				cb_player_can_move(char **map, double pos_x, double pos_y);
double			cb_get_player_new_position(double dir);

// * Utils
// ? srcs/utils/utils1.c
int				cb_get_first_char(char *input, int i);
char			*cb_free_return_null(char *ptr);
char			*cb_strjoinchr(char *str, char ch);
void			cb_print_msg(char *str, char *exit_code);
unsigned int	cb_get_hex_color(int r, int g, int b);

// ? srcs/utils/utils2.c
int				cb_count_lines(char **file, int flag);
int				cb_count_lines2(char **arr);
int				cb_map_width(char **map);
int				cb_map_height(char **map);
char			*cb_trim_colors(char *str);

// ? srcs/utils/utils3.c
int				cb_check_color(t_game *game);
int				cb_check_colors_int(t_game *game);

// * Validations
// ? srcs/validations/validations.c
int				cb_validate_args(int argc);
int				cb_validate_map_extension(char *map_str);

// ? srcs/validations/validations2.c
int				cb_initialize_file_values(t_game *game);
int				cb_validate_values(t_game *game);
int				cb_key_error(t_game *game);


// * Destroy
// ? srcs/validations/destroy.c
int				cb_destroy(t_game *game);
int				cb_validate_map_chars(char **map);
int				cb_check_map_walls(char **map);
