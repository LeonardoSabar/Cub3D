#ifndef STRUCT_H
# define STRUCT_H


#include "cub3d.h"

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


#endif
