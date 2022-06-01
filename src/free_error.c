/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:29:12 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/09 12:36:47 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	free_map(t_cell **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	free_exit(t_game *game)
{
	if (game)
	{
		if (game->mlx)
		{
			if (game->window)
				mlx_destroy_window(game->mlx, game->window);
			free(game->mlx);
		}
		if (game->map)
			free_map(game->map);
	}
	ft_putstr_fd("\nso_long closed\n", 1);
	exit(0);
}

void	error(t_game *game, char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free_exit(game);
}
