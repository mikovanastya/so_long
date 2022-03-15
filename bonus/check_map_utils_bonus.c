/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:15:08 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/12 18:26:23 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
