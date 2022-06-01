/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:22:41 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/09 13:06:37 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	move(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x].type != WALL)
	{
		if (game->map[new_y][new_x].type == EXIT && game->char_c <= 0)
		{
			ft_putstr_fd("\nyou win!!!\n", 0);
			free_exit(game);
		}			
		else if (game->map[new_y][new_x].type == COLLECTABLE)
		{
			game->char_c--;
			game->map[new_y][new_x].type = EMPTY;
		}	
		game->player_pos.x = new_x;
		game->player_pos.y = new_y;
		game->move++;
		ft_putstr_fd("\nMove: ", 0);
		ft_putnbr_fd(game->move, 0);
	}
}

int	input(int key, t_game *game)
{
	if (key == 53)
		free_exit(game);
	if (key == 13)
		move(game, game->player_pos.x, game->player_pos.y - 1);
	else if (key == 1)
		move(game, game->player_pos.x, game->player_pos.y + 1);
	else if (key == 0)
		move(game, game->player_pos.x - 1, game->player_pos.y);
	else if (key == 2)
		move(game, game->player_pos.x + 1, game->player_pos.y);
	return (0);
}
