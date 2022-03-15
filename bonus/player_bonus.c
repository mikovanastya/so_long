/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:30:00 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/14 16:19:57 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_check_gameover(t_prog *prog, t_vector *pos)
{
	if (prog->map.grid[pos->y][pos->x] == '!')
	{
		write(1, "GAME OVER\n", 10);
		exit(0);
	}
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
