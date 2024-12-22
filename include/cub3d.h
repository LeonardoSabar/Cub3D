#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/includes/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <memory.h>
# include <string.h>
# include <math.h>


<<<<<<< HEAD
WIN_WIDTH 800
WIN_HEIGHT 600

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif


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
}				game_t;
=======
# define BUFFER_SIZE 50

# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4 // player speed

typedef struct s_player //the player structure
{
 int  plyr_x; // player x position in pixels
 int  plyr_y; // player y position in pixels
 double angle; // player angle
 float fov_rd; // field of view in radians
 int  rot; // rotation flag
 int  l_r; // left right flag
 int  u_d; // up down flag
} t_player;

typedef struct s_ray //the ray structure
{
 double ray_ngl; // ray angle
 double distance; // distance to the wall
 int  flag;  // flag for the wall
} t_ray;

typedef struct s_data //the data structure
{
 char **map2d; // the map
 int  p_x;  // player x position in the map
 int  p_y;  // player y position in the map
 int  w_map;  // map width
 int  h_map;  // map height
} t_data;

typedef struct s_mlx //the mlx structure
{
 mlx_image_t  *img; // the image
 mlx_t   *mlx_p; // the mlx pointer
 t_ray   *ray; // the ray structure
 t_data   *dt; // the data structure
 t_player  *ply; // the player structure
} t_mlx;
>>>>>>> 0ff1b01a0f77c5c0a0c6014739e66514582a5cc8

#endif
