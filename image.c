/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:37:12 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/14 14:42:57 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_sprite_wall(t_prog prog, int i, int j)
{
	prog.sprite = ft_new_sprite(prog.mlx, "xpm/wall.xpm");
	prog.sprite.pos.x = i;
	prog.sprite.pos.y = j;
	mlx_put_image_to_window(prog.mlx, prog.window.ptr,
		prog.sprite.ptr, prog.sprite.pos.x, prog.sprite.pos.y);
	mlx_destroy_image(prog.mlx, prog.sprite.ptr);
}

void	draw_sprite_collectibles(t_prog prog, int i, int j)
{
	prog.sprite = ft_new_sprite(prog.mlx, "xpm/collectible.xpm");
	prog.sprite.pos.x = i;
	prog.sprite.pos.y = j;
	mlx_put_image_to_window(prog.mlx, prog.window.ptr,
		prog.sprite.ptr, prog.sprite.pos.x, prog.sprite.pos.y);
	mlx_destroy_image(prog.mlx, prog.sprite.ptr);
}

void	draw_sprite_exit(t_prog prog, int i, int j)
{
	prog.sprite = ft_new_sprite(prog.mlx, "xpm/finish.xpm");
	prog.sprite.pos.x = i;
	prog.sprite.pos.y = j;
	mlx_put_image_to_window(prog.mlx, prog.window.ptr,
		prog.sprite.ptr, prog.sprite.pos.x, prog.sprite.pos.y);
	mlx_destroy_image(prog.mlx, prog.sprite.ptr);
}

void	draw_sprite_player(t_prog prog, int i, int j, int anim_step)
{
	char	*str;
	char	*s1;
	char	*s2;

	s2 = ft_itoa(anim_step);
	s1 = ft_strjoin("xpm/player", s2);
	str = ft_strjoin(s1, ".xpm");
	free(s1);
	free(s2);
	prog.sprite = ft_new_sprite(prog.mlx, str);
	prog.sprite.pos.x = i;
	prog.sprite.pos.y = j;
	free(str);
	mlx_put_image_to_window(prog.mlx, prog.window.ptr,
		prog.sprite.ptr, prog.sprite.pos.x, prog.sprite.pos.y);
	mlx_destroy_image(prog.mlx, prog.sprite.ptr);
}
