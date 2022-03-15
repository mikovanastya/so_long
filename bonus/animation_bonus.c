/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:13:46 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/12 18:47:44 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_ground(t_prog *prog, int time, int i, int j)
{
	if (prog->map.grid[j][i] == '!')
	{
		if (time == 0)
		{
			draw_sprite_ground(*prog, i * 64, j * 64);
			draw_sprite_enemy(*prog, i * 64, j * 64, 1);
		}	
		if (time == 2000)
		{
			draw_sprite_ground(*prog, i * 64, j * 64);
			draw_sprite_enemy(*prog, i * 64, j * 64, 2);
		}	
		if (time == 4000)
		{
			draw_sprite_ground(*prog, i * 64, j * 64);
			draw_sprite_enemy(*prog, i * 64, j * 64, 0);
		}	
	}
}

int	animation_enemy(t_prog *prog, int time)
{
	int	i;
	int	j;

	j = 0;
	while (j < prog->map.height)
	{
		i = 0;
		while (i < prog->map.width)
		{
			enemy_ground(prog, time, i, j);
			i++;
		}
		j++;
	}
	return (0);
}

int	animation(t_prog *prog)
{
	static int	time = 0;

	animation_enemy(prog, time);
	if (time == 0)
	{
		draw_sprite_ground(*prog, prog->player.pos.x * 64,
			prog->player.pos.y * 64);
		draw_sprite_player(*prog, prog->player.pos.x * 64,
			prog->player.pos.y * 64, 0);
	}	
	if (time == 2000)
	{
		draw_sprite_ground(*prog, prog->player.pos.x * 64,
			prog->player.pos.y * 64);
		draw_sprite_player(*prog, prog->player.pos.x * 64,
			prog->player.pos.y * 64, 1);
	}	
	if (time++ > 4000)
		time = 0;
	return (0);
}
