#include "cub3d.h"

static void print_ray(t_ray ray) {
    printf(B"\nRay Info:\n"RST);
    printf("  ray_ngl: %lf\n", ray.ray_ngl);
    printf("  distance: %lf\n", ray.distance);
    printf("  flag: %d\n", ray.flag);
}

static void print_tile(t_tile tile) {
    printf(B"\nTile Info:\n"RST);
    printf("  base: %d\n", tile.base);
    printf("  width: %d\n", tile.width);
    printf("  height: %d\n", tile.height);
}

static void print_img(t_img img) {
    printf(B"\nImage Info:\n"RST);
    // Pode ser necessário ajustar dependendo da definição de mlx_texture_t e mlx_image_t
    printf("  texture: %p\n", (void*)img.texture);
    printf("  img: %p\n", (void*)img.img);
}

static void print_r_img(t_r_img r_img) {
    printf(B"\nRender Image Info:\n"RST);
    printf("  x: %d\n", r_img.x);
    printf("  y: %d\n", r_img.y);
    printf("  z: %d\n", r_img.z);
}

static void print_obj(t_obj obj) {
    printf(B"\nObject Info:\n"RST);
    printf("  onoff: %d\n", obj.onoff);
    print_img(obj.img);
    print_r_img(obj.sizes);
}

static void print_map(t_map *map) {
    printf(B"\nMap Info:\n"RST);
    while (map) {
        printf("  Line: %d, Column: %d, Content: %c\n", map->line, map->column, map->content);
        map = map->nxt; // Segue para o próximo mapa
    }
}


static  void print_texinfo(t_texinfo texinfo) {
    printf(B"\nTexture Info:\n"RST);
    printf("  north: %s\n", texinfo.north);
    printf("  south: %s\n", texinfo.south);
    printf("  west: %s\n", texinfo.west);
    printf("  east: %s\n", texinfo.east);
    printf("  floor[0]: %d, floor[1]: %d, floor[2]: %d, floor[3]: %d\n", texinfo.floor[0], texinfo.floor[1], texinfo.floor[2], texinfo.floor[3]);
    printf("  ceiling[0]: %d, ceiling[1]: %d, ceiling[2]: %d, ceiling[3]: %d\n", texinfo.ceiling[0], texinfo.ceiling[1], texinfo.ceiling[2], texinfo.ceiling[3]);
    printf("  size: %d\n", texinfo.size);
    printf("  index: %d\n", texinfo.index);
    printf("  x: %d\n", texinfo.x);
    printf("  y: %d\n", texinfo.y);
    printf("  step: %lf\n", texinfo.step);
    printf("  pos: %lf\n", texinfo.pos);
    printf("  hex_floor: %lu\n", texinfo.hex_floor);
    printf("  hex_ceiling: %lu\n", texinfo.hex_ceiling);
}

static void print_mapinfo(t_mapinfo mapinfo) {
    printf( B"\nMap Info:\n"RST);
    printf("  index_end_of_map: %d\n", mapinfo.index_end_of_map);
    printf("  line_count: %d\n", mapinfo.line_count);
    printf("  height: %d\n", mapinfo.height);
    printf("  width: %d\n", mapinfo.width);
    printf("  fd: %d\n", mapinfo.fd);
    printf("  path: %s\n", mapinfo.path);
}

static void print_map_matrix(char **map) {
    printf(B"\nMap Matrix:\n"RST);
    for (int i = 0; map[i]; i++) {
        printf("%s\n", map[i]);
    }
}

static void print_player(t_player player) {
    printf(B"\nPlayer Info:\n"RST);
    printf("  dir: %c\n", player.dir);
    printf("  has_moved: %d\n", player.has_moved);
    printf("  move_x: %d\n", player.move_x);
    printf("  move_y: %d\n", player.move_y);
    printf("  rotate: %d\n", player.rotate);
    printf("  pos_x: %lf\n", player.pos_x);
    printf("  pos_y: %lf\n", player.pos_y);
    printf("  dir_x: %lf\n", player.dir_x);
    printf("  dir_y: %lf\n", player.dir_y);
    printf("  plane_x: %lf\n", player.plane_x);
    printf("  plane_y: %lf\n", player.plane_y);
}

void print_game_info(t_game game) {
    printf(B"\nGame Info:\n"RST);
    printf("  is_horizon: %d\n", game.is_horizon);
    // Imprimir o mapa jogo
    print_map(game.map_position);
    print_player(game.player);
    print_texinfo(game.texinfo);
    print_mapinfo(game.mapinfo);
    print_tile(game.tile);
    print_ray(game.ray);
    print_obj(game.obj);
    print_map_matrix(game.map);
    // Pode imprimir outras partes como imagens se necessário
}