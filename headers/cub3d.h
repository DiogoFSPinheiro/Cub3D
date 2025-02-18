/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:09:32 by paulo-do          #+#    #+#             */
/*   Updated: 2025/01/06 19:23:07 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "../libraries/libft/libft.h"
# include "../libraries/printf/ft_printf.h"

# define PI 3.14159265359
# define P2 1.57079632679 // PI/2
# define P3 4.71238898038 //3*PI/2

# define FOV 1.04719755 //(PI / 3)

# define TEXTURE_H 64
# define TEXTURE_Y 64

# define WIDTH 1920
# define HEIGHT 1080

# define SQUARE 64
# define PLAYER_SIZE 20
# define OBSTACLE_COLOR 0x000000

# define DR 0.000545415 //(FOV / WIDTH)

typedef struct s_valid_map
{
	bool	so;
	bool	no;
	bool	we;
	bool	ea;
	bool	c;
	bool	f;
	bool	player;
}			t_valid_map;

typedef struct s_player_p
{
	int		f_y;
	int		f_x;
	int		y;
	int		x;
	char	player;
}		t_player_p;

typedef struct s_temp_map
{
	char		**lines;
	int			size;
	int			start;
	t_valid_map	*valid;
	t_player_p	*player;
}			t_temp_map;

typedef enum e_exit
{
	FAILURE,
	SUCCESS,
}	t_exit;

//--------- calculations -------
typedef struct s_horizontal_intersection
{
	int		mx;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	float	atan;
}	t_h_inter;

typedef struct s_vertical_intersection
{
	int		mx;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	float	ntan;
}	t_v_inter;

typedef struct s_ray_vars
{
	int		r;
	float	ra;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	ray_h;
	float	ray_v;
	float	wall_x;
	float	line;
	float	line_h;
	float	line_v;
}	t_ray_vars;
//--------- ------------ -------

//--------- texture calculations -------
typedef struct s_texture_vars
{
	int		y;
	float	ty;
	float	tx;
	float	ty_step;
	float	ty_offset;
}	t_texture_vars;

//----------------------------

typedef struct s_map
{
	int					width;
	int					height;
	char				**coord;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	player_delta_x;
	float	player_delta_y;
	float	player_angle;
}	t_player;

typedef struct s_tex
{
	void	*mlx_img;
	char	*path;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_mlx
{
	void		*mlx_connect;
	void		*mlx_win;
	t_player	*player;
	t_map		*map;
	t_img		img;
	t_tex		north_texture;
	t_tex		east_texture;
	t_tex		south_texture;
	t_tex		west_texture;
	int			color_top;
	int			color_bot;
	int			texture_nbr;
}	t_mlx;

// --------------- img_create.c ------------------ //

void	my_pixel_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);
void	render_background_top_bot(t_mlx *win, t_img *img);
int		get_pixel_color(t_tex *img, int x, int y);
// --------------- events.c --------------------- //

int		arrow_keys(int Key, t_mlx *mlx);
// --------------- draw_shapes.c ---------------- //

void	ft_update_player(int px, int py, t_img *img, t_mlx *win);
void	draw_square(t_img *img, int x, int y, int color);

// --------------- utils.c --------------------- //

int		ft_mod(int n);
void	set_up_win(t_mlx *win, t_temp_map *map);
float	line_length(float x1, float y1, float x2, float y2);
int		ft_circle_normalizer(float *ra);
void	ft_value_setter(float *val1, float *set1, float *val2, float *set2);
int		rgb_to_int(int red, int green, int blue);
char	*ft_copy_line(char *map, int max_line);

// --------------- raycast.c --------------------- //

void	raycaster(t_mlx *win);
void	get_horizontal_intersection(t_mlx *win, float ra, float *hx, float *hy);
void	get_vertical_intersection(t_mlx *win, float ra, float *vx, float *vy);
// --------------- wall_and_textures.c --------------------- //

void	ft_texture_picker(t_mlx *win, float ray_point, char c);
void	draw_3d_walls(t_mlx *win, float distance, int column, float hx);
// --------------- line_algo.c  --------------------- //

void	ft_bresenhams_alg(t_mlx *win, float end_x, float end_y, int color);
void	ft_vision_angle(t_mlx *win, float px, float py);
// --------------- clean_rotine.c --------------------- //

void	ft_cleanup_and_exit(t_mlx *mlx);
int		ft_close(t_mlx *mlx);
int		ft_event_checker(int Key, t_mlx *mlx);
// --------------- utils2.c --------------------- //

void	ft_rotate_right(t_mlx *mlx);
void	ft_rotate_left(t_mlx *mlx);
void	ft_init_vars(t_ray_vars	*vars, t_mlx *win);

//ft_get_map
char	*get_texture_path(t_temp_map *map, int c);
int		ft_get_max_line(int i, t_temp_map *map);
int		ft_get_colors(t_temp_map *map, int c);
char	**get_final_map(t_temp_map *map);
int		get_map_size(char **map);

//ft_setters
float	ft_set_player(t_mlx *win, char **map);
void	set_up_win(t_mlx *win, t_temp_map *map);
//ft_getters
int		ft_get_file_size(char *file, t_temp_map *map);

//val_exts
int		ft_check_file_name(char *file_name);

//ft_error
int		error_central(int error_code, t_temp_map *map);

//ft_getters
void	ft_get_map(t_temp_map **map, char *file, int i, int j);
int		ft_get_start_map(t_temp_map *map);

//freedom city
void	free_map_parse(t_temp_map **map);
void	free_split(char **str);
void	ft_free_pack(t_temp_map *map, char **temp);
void	ft_end_gnl(int fd, t_temp_map *map, char *line);

//color validations
int		col_val(t_temp_map *map, int i);
int		ft_invalid_start(t_temp_map *map, char c, int i);
int		check_extension(char *file_name, char *ext, int len);

//val_colo_utils
void	check_next_char(t_temp_map *map, int c, int i);
char	*ft_color_special(char *line, int j, int i, t_temp_map *map);

//ft_assets
void	check_textures(t_temp_map *map, int i);

char	*ft_remove_extra_spaces(char *str, t_temp_map *map);

//val_maps
void	check_map(t_temp_map *map, int start, int end, int i);

//flood
void	flood(t_temp_map *map, int y, int x, int map_size);
int		ft_check_first_last(char **map, int i);
int		check_the_sides(char **map, int y, int map_size);
void	ft_do_flood(t_temp_map *map, int start, int end, int i);

//ft_checkers
void	first_check(t_temp_map *map, int i);
int		check_line_player(int start, char c, t_temp_map *map);

//ft_validations
void	ft_validations(char *argv[]);
int		is_whitespace(char c);

#endif
