/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:57:19 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/09 13:05:21 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	open_img(char *path, t_game *game, t_image *img)
{
	img->pointer = mlx_xpm_file_to_image(game->mlx,
			path,
			&img->size.x, &img->size.y);
	if (!img->pointer)
		error(game, "Bad path img");
}

void	open_images(t_game *game)
{
	open_img("img/player1_0.xpm", game, &game->imgs[0]);
	open_img("img/player1_1.xpm", game, &game->imgs[1]);
	open_img("img/player1_2.xpm", game, &game->imgs[2]);
	open_img("img/player1_3.xpm", game, &game->imgs[3]);
	open_img("img/door_01.xpm", game, &game->imgs[4]);
	open_img("img/door_02.xpm", game, &game->imgs[5]);
	open_img("img/coin1.xpm", game, &game->imgs[6]);
	open_img("img/coin2.xpm", game, &game->imgs[7]);
	open_img("img/coin3.xpm", game, &game->imgs[8]);
	open_img("img/coin4.xpm", game, &game->imgs[9]);
	open_img("img/sand.xpm", game, &game->imgs[10]);
	open_img("img/wall.xpm", game, &game->imgs[11]);
}
