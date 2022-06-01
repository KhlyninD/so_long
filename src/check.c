/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:42:18 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/09 13:28:22 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_is_char(char *str, t_check *check, t_game *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'P')
			error(game, "Bad char!");
		if (str[i] == 'C')
			check->char_c++;
		else if (str[i] == 'E')
			check->char_e++;
		else if (str[i] == 'P')
			check->char_p++;
		if (check->char_p > 1)
			error(game, "Many P!");
		i++;
	}
	if (!check->read && (check->char_c < 1 || check->char_e < 1
			|| check->char_p < 1))
		error(game, "Not C or/and E or/and P");
}

static void	map_is_one(char *str, int first_last_line, int len, t_game *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (first_last_line && str[i] != '1')
			error(game, "Not perimeter 1!");
		else if ((str[0] != '1') || (str[len - 1] != '1'))
			error(game, "Not perimeter 1!");
		i++;
	}
}

static void	check_loop(t_check *check, t_game *game)
{
	int	i;

	check->len_x = -1;
	check->read = 1;
	check->len_y = 0;
	while (check->read > 0)
	{
		check->prev_len = check->len_x;
		check->read = get_next_line(check->fd, &check->line);
		if (!check->line)
			error(game, "Bad map");
		check->len_x = ft_strlen(check->line);
		if (check->prev_len != -1 && check->prev_len != check->len_x)
			error(game, "Map not rectangle!");
		if (check->len_y++ == 0 || check->read == 0)
			map_is_one(check->line, 1, check->len_x, game);
		else
			map_is_one(check->line, 0, check->len_x, game);
		check_is_char(check->line, check, game);
		free(check->line);
	}
}

void	check_is_map(char *file, t_game *game, t_check *check)
{
	check->char_e = 0;
	check->char_p = 0;
	check->char_c = 0;
	check->fd = open(file, O_RDWR);
	if (check->fd < 0)
		error(game, "Not open file!");
	check_loop(check, game);
	close(check->fd);
}
