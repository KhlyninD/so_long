/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:57:15 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/09 13:05:08 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_file_name(char *file, t_game *game)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 1] != 'r' || file[i - 2] != 'e'
		|| file[i - 3] != 'b' || file[i - 4] != '.')
		error(game, "Bad name file!");
}

static t_char	type(char definer)
{
	if (definer == '1')
		return (WALL);
	if (definer == 'C')
		return (COLLECTABLE);
	if (definer == 'E')
		return (EXIT);
	return (EMPTY);
}

static void	init_line_map(char *line, t_game *game, int y)
{
	int	x;

	x = 0;
	while (line[x])
	{
		game->map[y][x].type = type(line[x]);
		game->map[y][x].position.x = x * IMG_SIZE;
		game->map[y][x].position.y = y * IMG_SIZE;
		if (line[x] == 'P')
		{
			game->player_pos.x = x;
			game->player_pos.y = y;
		}
		x++;
	}
	game->map[y][x].type = 0;
	game->window_size.x = x * IMG_SIZE;
}

static void	parsing(char *file, t_game *game, t_check *check)
{
	int	y;

	game->map = malloc(sizeof(t_cell *) * (check->len_y + 1));
	if (!game->map)
		error(game, "bad malloc map!");
	check->fd = open(file, O_RDWR);
	check->read = 1;
	y = 0;
	while (check->read)
	{
		check->read = get_next_line(check->fd, &check->line);
		game->map[y] = malloc(sizeof(t_cell) * (check->len_x + 1));
		if (!game->map[y])
			error(game, "bad malloc game_map");
		init_line_map(check->line, game, y++);
		free(check->line);
	}
	close(check->fd);
	game->window_size.y = y * IMG_SIZE;
	game->map[y] = NULL;
}

void	map_init(t_game *game, int argc, char **argv)
{
	t_check		check;

	if (argc == 1)
		error(game, "Not arguments!");
	if (argc > 2)
		error(game, "Many arguments!");
	check_file_name(argv[1], game);
	ft_bzero(&check, sizeof(t_check));
	check_is_map(argv[1], game, &check);
	parsing(argv[1], game, &check);
	game->char_c = check.char_c;
}
