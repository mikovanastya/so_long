/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:46:13 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/12 18:26:48 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_sprites_on_map(t_prog prog)
{
	int		i;
	int		j;
	char	ch;

	j = 0;
	while (j < prog.map.height)
	{
		i = 0;
		while (i < prog.map.width)
		{
			ch = prog.map.grid[j][i];
			if (ch == '1')
				draw_sprite_wall(prog, i * 64, j * 64);
			else if (ch == 'C')
				draw_sprite_collectibles(prog, i * 64, j * 64);
			else if (ch == 'E')
				draw_sprite_exit(prog, i * 64, j * 64);
			else if (ch == 'P')
				draw_sprite_player(prog, i * 64, j * 64, 0);
			else if (ch == '!')
				draw_sprite_enemy(prog, i * 64, j * 64, 0);
			i++;
		}
		j++;
	}
}
