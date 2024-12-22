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

#endif
