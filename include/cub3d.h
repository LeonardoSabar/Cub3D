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


typedef struct s_cub3d
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}				cub3d_t;

#endif
