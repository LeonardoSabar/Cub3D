#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "cub3d.h"

//****************************************************************************//
//                                 Functions                                  //
//****************************************************************************//

int				check_map_sides(t_mapinfo *map, char **map_tab);
void			clean_exit(t_game *data, int code);
int				create_map(t_game *data, char **file, int i);
int				err_msg(char *message, int code);
size_t			find_biggest_len(t_mapinfo *map, int i);
void			free_resources(t_game *data);
void			free_tab(void **tab);
int				get_map_elements(t_game *data, char **file);
int				get_map_list_node(t_game *data, char **map_tab);
char			*get_next_line(int fd);
void			init_data(t_game *data);
int				is_a_white_space(char c);
int				required_rgb_colors(int *color_array);
int				parse_data(char *path, t_game *data);
int				parse_file(char *file, bool cub);
int				parse_map(t_game *data, char **map);
int				parse_textures(t_texinfo *textures);
int				parsing(t_game *data, char **argv);
int				set_floor_and_ceiling_colors(t_texinfo *textures, char *line, int j);
int				special_ft_strncmp(const char *str1, const char *str2, size_t n);
int				unit_circle(float angle, char c);
int				inter_check(float angle, float *inter, float *step, t_game *gm);
int				wall_hit(float x, float y, t_game *gm);
float			get_h_inter(t_game *gm, float angl);
float			get_v_inter(t_game *gm, float angl);
float			nor_angle(float angle);
void			render_wall(t_game *gm, int ray);
void			draw_wall(t_game *gm, int ray, int t_pix, int b_pix);
void			init_background(t_game *gm);
void			mlx_key(mlx_key_data_t keydata, void *ml);
void			ft_reles(mlx_key_data_t keydata, t_game *gm);
void			rotate_player(t_game *gm, int i);
void			move_player(t_game *gm, double move_x, double move_y);
void			hook(t_game *gm, double move_x, double move_y);
void			game_loop(void *game);
void			cast_rays(t_game *gm);
float			pytheorem(float a, float b);
int				v_unit_circle(float angle);
int				h_unit_circle(float angle);
void			raycast(t_game *gm);
uint32_t		reverse_bytes(unsigned int c);
mlx_texture_t	*get_texture(t_game *gm);
void			game_loop2(void *game);
t_texture  		*create_texture(t_game *gm);
void			put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color);
void			draw_wall2(t_game *gm, int t_pix, int b_pix, double wall_h);
uint32_t		reverse_bytes(unsigned int c);
void			start_cam_infor(t_game *game);

void			print_game_info(t_game game);

#endif
