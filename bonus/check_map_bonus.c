/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:16:14 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/15 15:29:10 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	valid_name(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'r' || file[len - 2] != 'e'
		|| file[len - 3] != 'b' || file[len - 4] != '.')
	{	
		write(1, "Error: wrong map name!\n", 23);
		return (1);
	}
	return (0);
}

int	check_map_walls(char **grid, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if ((grid[i][j] != '1') && ((i == 0) || (j == 0)
			|| (j == width - 1) || (i == height - 1)))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	no_symb(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!ft_strchr("01ECP!", map->grid[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_grid(t_prog *prog)
{
	fill_map_counts(prog);
	if (prog->map.exits == 0 || prog->map.collectibles == 0
		|| prog->map.players != 1)
	{
		write(1, "Error:Wrong map!\n", 17);
		exit(1);
	}
	if (no_symb(&prog->map))
	{
		write(1, "Error: Wrong input symbols!", 27);
		exit(1);
	}
	if (check_map_walls(prog->map.grid, prog->map.height, prog->map.width))
		exit (1);
	return (0);
}
