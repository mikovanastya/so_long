/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:47:22 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/14 14:43:59 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_height_width(t_prog *prog, char *file_name)
{
	int		fd;
	char	*line;

	prog->map.height = 0;
	prog->map.width = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		prog->map.width = ft_strlen(line);
		prog->map.height++;
		free (line);
		line = get_next_line(fd);
		if (line && ((int)ft_strlen(line) != prog->map.width))
		{	
			free(line);
			close(fd);
			write(1, "wrong size map!\n", 16);
			exit (1);
		}	
	}
	close(fd);
}

int	get_map_grid(t_prog *prog, char *file_name)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	prog->map.grid = malloc(sizeof(char *) * (prog->map.height + 1));
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		prog->map.grid[count] = line;
		count++;
		line = get_next_line(fd);
	}
	prog->map.grid[prog->map.height] = 0;
	close(fd);
	return (0);
}

static int	pressing_the_red_cross(void)
{
	exit (0);
}

int	main(int argc, char **argv)
{
	t_prog	prog;

	if (argc != 2)
	{
		write(1, "Error:Wrong number of arguments!", 32);
		exit(1);
	}
	if (valid_name(argv[1]))
		exit (1);
	map_height_width(&prog, argv[1]);
	get_map_grid(&prog, argv[1]);
	check_map_grid(&prog);
	prog.mlx = mlx_init();
	prog.window.width = prog.map.width * 64;
	prog.window.height = prog.map.height * 64;
	prog.window.ptr = mlx_new_window(prog.mlx, prog.window.width,
			prog.window.height, "so_long!");
	draw_map(&prog);
	map_get_player_pos(&prog);
	mlx_key_hook(prog.window.ptr, ft_input, &prog);
	mlx_hook(prog.window.ptr, 17, 0, &pressing_the_red_cross, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
