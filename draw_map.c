/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:38:44 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/14 16:11:42 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bit_per_pixel, &img.line_size,
			&img.endian);
	return (img);
}

void	draw_sprite_ground(t_prog prog, int i, int j)
{
	prog.sprite = ft_new_sprite(prog.mlx, "xpm/purple.xpm");
	prog.sprite.pos.x = i;
	prog.sprite.pos.y = j;
	mlx_put_image_to_window(prog.mlx, prog.window.ptr,
		prog.sprite.ptr, prog.sprite.pos.x, prog.sprite.pos.y);
	mlx_destroy_image(prog.mlx, prog.sprite.ptr);
}

void	draw_map_ground(t_prog prog)
{
	int	i;
	int	j;

	i = 0;
	while (i < prog.map.height)
	{
		j = 0;
		while (j < prog.map.width)
		{
			draw_sprite_ground(prog, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	steps(t_prog *prog)
{
	char	*str;

	str = ft_itoa(prog->player.step_count);
	mlx_string_put(prog->mlx, prog->window.ptr, 25, 15, 0x701370, str);
	free(str);
}

void	draw_map(t_prog *prog)
{
	draw_map_ground(*prog);
	draw_sprites_on_map(*prog);
	steps(prog);
}
