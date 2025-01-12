/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:34:21 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 14:35:08 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_char
{
	char			character;
	struct s_char	*next;
}					t_char;

typedef struct s_listgnl
{
	int		fd;
	int		pos;
	int		read;
	int		len;
	int		exist_n;
	char	*buffer;
	t_char	*string;
}			t_listgnl;

char	*get_next_line(int fd);
void	*free_all(t_char **str);
t_char	*ft_node(char c);
int		ft_lstsize_gnl(t_char *lst, t_listgnl *struc);
int		ft_find_n(t_listgnl *struc);
char	*ft_build_string(t_listgnl *struc);
char	*ft_add_lk(t_listgnl *struc);
t_char	*add_node_to_end(t_listgnl *struc, t_char *end, char c);

#endif