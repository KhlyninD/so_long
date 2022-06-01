/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:54:19 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/09 13:15:07 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	render_image(t_cell cell, t_game *game, t_vector pos)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->imgs[10].pointer, pos.x, pos.y);
	if (cell.type == WALL)
		mlx_put_image_to_window(game->mlx, game->window,
			game->imgs[11].pointer, pos.x, pos.y);
	else if (cell.type == EXIT)
	{
		if (game->char_c == 0)
			mlx_put_image_to_window(game->mlx, game->window,
				game->imgs[5].pointer, pos.x, pos.y);
		else
			mlx_put_image_to_window(game->mlx, game->window,
				game->imgs[4].pointer, pos.x, pos.y);
	}
	else if (cell.type == COLLECTABLE)
		mlx_put_image_to_window(game->mlx, game->window,
			game->img_c, pos.x, pos.y);
}

static void	render_text(t_game *game)
{
	char	*str;

	str = ft_itoa(game->move);
	mlx_string_put(game->mlx, game->window,
		IMG_SIZE * 0.1,
		IMG_SIZE * 0.2,
		-16776961, "MOVE");
	mlx_string_put(game->mlx, game->window,
		IMG_SIZE * 1.2,
		IMG_SIZE * 0.2,
		-16776961, str);
	free(str);
}

static void	player_animation(t_game *game)
{
	if (game->fr_player <= 5)
		game->img_player = game->imgs[0].pointer;
	else if (game->fr_player <= 10)
		game->img_player = game->imgs[1].pointer;
	else if (game->fr_player <= 15)
		game->img_player = game->imgs[2].pointer;
	else if (game->fr_player <= 20)
		game->img_player = game->imgs[3].pointer;
	game->fr_player++;
	if (game->fr_player > 20)
		game->fr_player = 0;
}

static void	c_animation(t_game *game)
{
	if (game->fr_c <= 5)
		game->img_c = game->imgs[6].pointer;
	else if (game->fr_c <= 10)
		game->img_c = game->imgs[7].pointer;
	else if (game->fr_c <= 15)
		game->img_c = game->imgs[8].pointer;
	else if (game->fr_c <= 20)
		game->img_c = game->imgs[9].pointer;
	game->fr_c++;
	if (game->fr_c > 20)
		game->fr_c = 0;
}

int	render(t_game *game)
{
	int		x;
	int		y;

	player_animation(game);
	c_animation(game);
	mlx_clear_window(game->mlx, game->window);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x].type)
		{
			render_image(game->map[y][x], game, game->map[y][x].position);
			if (game->player_pos.x == x && game->player_pos.y == y)
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_player, game->map[y][x].position.x,
					game->map[y][x].position.y);
			x++;
		}
		y++;
	}
	render_text(game);
	return (0);
}
