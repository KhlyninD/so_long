/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:23:26 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/09 13:13:20 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef IMG_SIZE
#  define IMG_SIZE 40
# endif

typedef enum e_char
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	EXIT = 'E',
}	t_char;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_cell
{
	char		type;
	t_vector	position;
}	t_cell;

typedef struct s_check
{
	int			read;
	char		*line;
	int			len_x;
	int			prev_len;
	int			fd;
	int			len_y;
	int			char_p;
	int			char_e;
	int			char_c;
}	t_check;

typedef struct s_image
{
	void		*pointer;
	t_vector	size;
}				t_image;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_vector	window_size;
	t_cell		**map;
	int			char_c;
	int			move;
	t_vector	player_pos;
	t_image		imgs[12];
	void		*img_player;
	int			fr_player;
	void		*img_c;
	int			fr_c;
}	t_game;

int		get_next_line(int fd, char **line);
void	error(t_game *game, char *str);
void	map_init(t_game *game, int argc, char **argv);
void	check_is_map(char *file, t_game *game, t_check *check);
int		render(t_game *game);
void	open_images(t_game *game);
int		free_exit(t_game *game);
int		input(int key, t_game *game);

#endif