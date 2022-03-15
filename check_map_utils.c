/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:43:34 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/14 16:19:27 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check_gameover(t_prog *prog, t_vector *pos)
{
	if (prog->map.grid[pos->y][pos->x] == 'E')
	{
		if (prog->map.collectibles == 0)
		{
			write(1, "YOU ARE WIN!\n", 13);
			exit(0);
		}
	}
	return (0);
}

void	count_symbols(t_prog *prog, char simbol)
{
	if (simbol == '0')
		prog->map.space++;
	if (simbol == '1')
		prog->map.walls++;
	if (simbol == 'C')
		prog->map.collectibles++;
	if (simbol == 'E')
		prog->map.exits++;
	if (simbol == 'P')
		prog->map.players++;
	if (simbol == '!')
		prog->map.enemy++;
}

void	reset_map_counts(t_prog *prog)
{
	prog->map.walls = 0;
	prog->map.space = 0;
	prog->map.collectibles = 0;
	prog->map.exits = 0;
	prog->map.players = 0;
	prog->map.enemy = 0;
}

void	fill_map_counts(t_prog *prog)
{
	int	str_cnt;
	int	col_cnt;

	str_cnt = 0;
	col_cnt = 0;
	reset_map_counts(prog);
	while (str_cnt < prog->map.height)
	{
		while (col_cnt <= prog->map.width)
		{
			count_symbols(prog, prog->map.grid[str_cnt][col_cnt]);
			col_cnt++;
		}
		str_cnt++;
		col_cnt = 0;
	}
}
