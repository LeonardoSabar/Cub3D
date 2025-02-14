#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/include/libft.h"
# include "colors.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <memory.h>
# include <string.h>
# include <math.h>
# include <errno.h>

# define DEBUG 0
# define DEBUGHARD 0

#define DELAY_ITERATIONS 50000000
#define INTRO_HEIGHT 8

# define SUCCESS 0
# define ERROR 1

# define WIDTH 1920
# define HEIGHT 1080
# define FOV 66
# define ROT_SPEED 0.040
# define MAX_MAP_W 480
# define MAX_MAP_H 270
# define CYAN 0x00FFFF // Usar colors.h

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif


//****************************************************************************//
//                                  Structs                                   //
//****************************************************************************//

enum e_color {
	A = 0xFF000000,
	R = 0x00FF0000,
	G = 0x0000FF00,
	B = 0x000000FF
};

typedef struct s_render_img
{
	double	x;
	double	y;
	int32_t	index;
}	t_r_img;

typedef struct	s_ray
{
	t_r_img	*info;
	double	ray_ngl;
	double	distance;
	int		flag;
}				t_ray;

typedef struct s_tile
{
	int	base;
	int	width;
	int	height;
}	t_tile;

typedef struct s_image
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
}	t_img;

typedef struct s_object
{
	int		onoff;
	t_img	img;
	t_r_img	sizes;
}	t_obj;

typedef struct s_map
{
	int				line;
	int				column;
	char			content;
	struct s_map	*nxt;
	struct s_map	*prv;
	struct s_map	*up;
	struct s_map	*down;
}	t_map;

typedef struct s_cam
{
	int		plr_x;
	int		plr_y;
	int		l_r;
	int		rotation;
	double	angle;
	float	fov_plr;
}	t_cam;

typedef struct	s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
}	t_texture;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	int				size;
	int				index;
	int				x;
	int				y;
	double			step;
	double			pos;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	t_texture		*tex;
}	t_texinfo;

typedef struct s_mapinfo
{
	int			index_end_of_map;
	int			line_count;
	int			height;
	int			width;
	int			fd;
	char		*path;
	char		**file;
}	t_mapinfo;

typedef struct s_player
{
	char	dir;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	int			is_horizon;
	char		**parse_map;
	char		**map;
	t_player	player;
	t_texinfo	*texinfo;
    t_mapinfo	mapinfo;
	mlx_image_t	*img;
	mlx_image_t	*game;
	mlx_image_t	*wall_img;
	mlx_image_t	*bg_img;
	t_tile		tile;
	mlx_t		*mlx_on;
	t_map		*map_position;
	t_cam		*cam;
	t_ray		ray;
	t_obj		obj;
}	t_game;


//****************************************************************************//
//                                 Functions                                  //
//****************************************************************************//

int     check_map_sides(t_mapinfo *map, char **map_tab);
void    clean_exit(t_game *data, int code);
int     create_map(t_game *data, char **file, int i);
int     err_msg(char *message, int code);
size_t  find_biggest_len(t_mapinfo *map, int i);
void    free_resources(t_game *data);
void    free_tab(void **tab);
int     get_map_elements(t_game *data, char **file);
int     get_map_list_node(t_game *data, char **map_tab);
char   *get_next_line(int fd);
void    init_data(t_game *data);
int     is_a_white_space(char c);
int		required_rgb_colors(int *color_array);
int     parse_data(char *path, t_game *data);
int     parse_file(char *file, bool cub);
int     parse_map(t_game *data, char **map);
int     parse_textures(t_texinfo *textures);
int     parsing(t_game *data, char **argv);
int     set_floor_and_ceiling_colors(t_texinfo *textures, char *line, int j);
int		special_ft_strncmp(const char *str1, const char *str2, size_t n);
t_texture	*create_texture(t_game *gm);
void	put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color);
void    hook(t_game *gm, double move_x, double move_y);
//void    game_loop(void *game);
void    game_loop2(void *game);
void    move_player(t_game *gm, double move_x, double move_y);
void    rotate_player(t_game *gm, int direction);
void	ft_reles(mlx_key_data_t keydata, t_game *gm);
void	mlx_key(mlx_key_data_t keydata, void *ml);
int     unit_circle(float angle, char c);
int		inter_check(float angle, float *inter, float *step, t_game *gm);
int		wall_hit(float x, float y, t_game *gm);
float	get_h_inter(t_game *gm, float angl);
float	get_v_inter(t_game *gm, float angl);
void	cast_rays(t_game *gm);
void    init_background(t_game *gm);
float	nor_angle(float angle);
float	pytheorem(float a, float b);
int		h_unit_circle(float angle);
int		v_unit_circle(float angle);
uint32_t	reverse_bytes(unsigned int c);
void    init_mini_map(t_game *gm);
mlx_texture_t    *get_texture(t_game *gm);
void	draw_wall2(t_game *gm, int t_pix, int b_pix, double wall_h);
void	render_wall(t_game *gm, int ray);



void print_game_info(t_game game);
void intro(void);

#endif
