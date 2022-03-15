/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:22:24 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/12 18:26:31 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_get_player_pos(t_prog *prog)
{
	int		i;
	int		j;

	j = 0;
	while (prog->map.grid[j])
	{
		i = 0;
		while (prog->map.grid[j][i])
		{
			if (prog->map.grid[j][i] == 'P')
			{
				prog->player.pos.x = i;
				prog->player.pos.y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

int	ft_input(int keynum, t_prog *prog)
{
	map_get_player_pos(prog);
	if (keynum == ESC)
		exit(0);
	if (keynum == A)
		player_move_left(prog);
	if (keynum == S)
		player_move_down(prog);
	if (keynum == D)
		player_move_right(prog);
	if (keynum == W)
		player_move_up(prog);
	draw_map(prog);
	return (0);
}
