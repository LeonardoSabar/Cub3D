/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:07:02 by leobarbo          #+#    #+#             */
/*   Updated: 2024/10/29 00:16:37 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	parse_args(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	parse_extention(char *file)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	parse_file(char *file)
{
	int fd;
	char *line;
	int i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	i = 0;
	while (get_next_line(fd, &line) > 0) // usar gnl 42
	{
		if (line[0] == '1')
			i++;
		free(line);
	}
	if (i == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	close(fd);
}

void	parsing(char *file)
{
	// parse_extention(file);
	// parse_args();
	// parse_file(file);
	// parse_textures();
	// parse_sprites();
	// parse_colors();
}
int	main(int argc, char **argv)
{
	cub3d_t	game;
	
	// parsing(argv[1]);
	// init();
	// render();
	// game_loop();
	// free();
}
