/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:58:23 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/09 13:06:04 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_struct_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < 14)
		game->imgs[i++].pointer = NULL;
	game->mlx = NULL;
	game->window = NULL;
	game->char_c = 0;
	game->move = 0;
	game->window_size.x = 0;
	game->window_size.y = 0;
	game->player_pos.x = 0;
	game->player_pos.y = 0;
	game->map = NULL;
	game->img_player = NULL;
	game->fr_player = 0;
	game->img_c = NULL;
	game->fr_c = 3;
}

static void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, "Not init mlx!");
	game->window = mlx_new_window(game->mlx,
			game->window_size.x,
			game->window_size.y,
			"so_long");
	if (!game->window)
		error(game, "Not init window!");
	open_images(game);
	mlx_hook(game->window, 17, 0, free_exit, game);
	mlx_hook(game->window, 2, 0, input, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_struct_game(&game);
	map_init(&game, argc, argv);
	game_init(&game);
	return (0);
}
