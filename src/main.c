/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:07:02 by leobarbo          #+#    #+#             */
/*   Updated: 2024/10/30 00:08:05 by leobarbo         ###   ########.fr       */
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
	if ((ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4)) || ft_strlen(file) < 5)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

char	*ft_read_all(int fd)
{
	int		chars_readed;
	char	*temp_buffer;
	char	*file_string;
	char	*aux;

	chars_readed = 1;
	temp_buffer = (char *) malloc((BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (0);
	file_string = ft_strdup("");
	while (chars_readed > 0)
	{
		chars_readed = read(fd, temp_buffer, BUFFER_SIZE);
		temp_buffer[chars_readed] = '\0';
		aux = file_string;
		file_string = ft_strjoin(file_string, temp_buffer);
		free(aux);
	}
	free(temp_buffer);
	return (file_string);
}

char	**parse_file(char *file)
{
	int		fd;
	char	*temp_map;
	char	**map;

	temp_map = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		free(temp_map);
		return (0);
	}
	temp_map = ft_read_all(fd);
	map = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
	return (map);
}

void	parsing(char *file, int args)
{
	parse_extention(file);
	parse_args(args);
	parse_file(file);
	// parse_textures();
	// parse_sprites();
	// parse_colors();
}
int	main(int argc, char **argv)
{
	
	parsing(argv[1], argc);
	

	
	// init();
	// render();
	// game_loop();
	// free();
}
