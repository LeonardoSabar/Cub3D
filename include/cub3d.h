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

# define SUCCESS 0
# define ERROR 1

# define WIDTH 1920
# define HEIGHT 1080
# define FOV 66
# define ROT_SPEED 0.040
# define MAX_MAP_W 480
# define MAX_MAP_H 270
# define CYAN 0x00FFFF

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
	// struct s_map	*up;  implementar
	// struct s_map	*down;  implementar
}	t_map;

typedef struct s_cam
{
	int		plr_x;
	int		plr_y;
	int		rotation;
	int		l_r;
	double	angle;
	float	fov_plr;
}	t_cam;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor; // implementar 4 posição para transparência, fixar 255
	int				*ceiling; // implementar 4 posição para transparência, fizar 255
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_mapinfo;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_game
{
	int			is_horizon;
	char		**parse_map;
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

void    clean_exit(t_game *data, int code);
void    free_tab(void **tab);
void    init_data(t_game *data);
int     fill_color_textures(t_texinfo *textures, char *line, int j);
int     parse_file(char *file, bool cub);
int     parse_data(char *path, t_game *data);
size_t  find_biggest_len(t_mapinfo *map, int i);
int     is_a_white_space(char c);
int     err_msg(char *message, int code);
int     is_blank_line(const char *line);
int     get_file_data(t_game *data, char **file);
void	free_resources(t_game *data);
int		parse_map(t_game *data, char **map);
char   *get_next_line(int fd);
int		check_map_sides(t_mapinfo *map, char **map_tab);
int		create_map(t_game *data, char **file, int i);
int     parsing(t_game *data, char **argv);
int		parse_textures(t_texinfo *textures);

#endif


/*

typedef struct s_textures {
    char *north;
    char *south;
    char *west;
    char *east;
}				t_textures;

typedef struct s_player
{
    char    direction;
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
    float   move_x;
    float   move_y;
    float   angle;
}				t_player;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_mapinfo;

typedef struct s_game
{
    void        *mlx;
    void        *windows;
    int         width;
    int         height;
    t_mapinfo   mapinfo;
    t_player    player;
    char        **map;
	t_textures	textures;
}				t_game;


*/
