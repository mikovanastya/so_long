/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:30:00 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/12 19:07:01 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_right(t_prog *prog)
{
	t_vector	next_pos;

	next_pos = prog->player.pos;
	next_pos.x += 1;
	map_check_gameover(prog, &next_pos);
	if (prog->map.grid[next_pos.y][next_pos.x] != '1' &&
		prog->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (prog->map.grid[next_pos.y][next_pos.x] == 'C')
			prog->map.collectibles--;
		prog->map.grid[next_pos.y][next_pos.x - 1] = '0';
		prog->map.grid[next_pos.y][next_pos.x] = 'P';
		prog->player.step_count++;
		prog->player.pos.x += 1;
	}
}

void	player_move_left(t_prog *prog)
{
	t_vector	next_pos;

	next_pos = prog->player.pos;
	next_pos.x -= 1;
	map_check_gameover(prog, &next_pos);
	if (prog->map.grid[next_pos.y][next_pos.x] != '1' &&
		prog->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (prog->map.grid[next_pos.y][next_pos.x] == 'C')
			prog->map.collectibles--;
		prog->map.grid[next_pos.y][next_pos.x + 1] = '0';
		prog->map.grid[next_pos.y][next_pos.x] = 'P';
		prog->player.step_count++;
		prog->player.pos.x -= 1;
	}
}

void	player_move_up(t_prog *prog)
{
	t_vector	next_pos;

	next_pos = prog->player.pos;
	next_pos.y -= 1;
	map_check_gameover(prog, &next_pos);
	if (prog->map.grid[next_pos.y][next_pos.x] != '1' &&
		prog->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (prog->map.grid[next_pos.y][next_pos.x] == 'C')
			prog->map.collectibles--;
		prog->map.grid[next_pos.y + 1][next_pos.x] = '0';
		prog->map.grid[next_pos.y][next_pos.x] = 'P';
		prog->player.step_count++;
		prog->player.pos.y -= 1;
	}
}

void	player_move_down(t_prog *prog)
{
	t_vector	next_pos;

	next_pos = prog->player.pos;
	next_pos.y += 1;
	map_check_gameover(prog, &next_pos);
	if (prog->map.grid[next_pos.y][next_pos.x] != '1' &&
		prog->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (prog->map.grid[next_pos.y][next_pos.x] == 'C')
			prog->map.collectibles--;
		prog->map.grid[next_pos.y - 1][next_pos.x] = '0';
		prog->map.grid[next_pos.y][next_pos.x] = 'P';
		prog->player.step_count++;
		prog->player.pos.y += 1;
	}
}
