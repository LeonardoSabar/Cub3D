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

typedef struct	s_ray
{
 double	ray_ngl;
 double	distance;
 int	flag;
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

typedef struct s_render_img
{
	int	x;
	int	y;
	int	z;
}	t_r_img;

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

typedef struct s_texinfo
{
	char			*hexadecimal_floor;
	char			*hexadecimal_ceiling;
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
	char		**parse_map; // Confirmar se esta sendo utilizada
	char		**map;
	t_player	player;
	t_texinfo	texinfo;
    t_mapinfo	mapinfo;
	mlx_image_t	*img;
	mlx_image_t	*game;
	mlx_image_t	*p_img;
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

void print_game_info(t_game game);
void intro(void);

#endif
