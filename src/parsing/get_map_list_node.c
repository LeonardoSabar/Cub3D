/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_list_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:41:21 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/12 21:59:43 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_map *create_new_map_node(int line, int column, char content)
{
    t_map *new_node = malloc(sizeof(t_map));
    if (!new_node) {
        return NULL;
    }
    new_node->line = line;
    new_node->column = column;
    new_node->content = content;
    new_node->nxt = NULL;
    new_node->prv = NULL;
    new_node->up = NULL;
    new_node->down = NULL;
    return new_node;
}

static void link_nodes(t_map *current, t_map *previous, t_map *up)
{
    if (previous != NULL) {
        previous->nxt = current;
        current->prv = previous;
    }
    if (up != NULL) {
        current->up = up;
        up->down = current;
    }
}

static void cleanup_map(t_map **head) 
{
    while (*head) {
        t_map *temp = *head;
        *head = (*head)->nxt;
        free(temp);
    }
}

static t_map *fill_map_list(char **map_tab, int height, int width) 
{
    t_map *head = NULL; 
    t_map *current = NULL; 
    t_map *previous = NULL; 
    t_map *up = NULL;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char content = map_tab[i][j];
            if (content == ' ' || content == '\t') continue;
            current = create_new_map_node(i, j, content);
            if (!current) {
                cleanup_map(&head); 
                return NULL;
            }
            if (!head) head = current;
            else link_nodes(current, previous, up);
            previous = current;
            if (i > 0) up = previous;
        }
    }
    return head;
}

int get_map_list_node(t_game *data, char **map_tab) {
    data->map_position = fill_map_list(map_tab, data->mapinfo.height, data->mapinfo.width);
    if (!data->map) {
        return err_msg("Could not allocate memory", 1);
    }
    return SUCCESS;
}