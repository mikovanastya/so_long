/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:47:29 by rtwitch           #+#    #+#             */
/*   Updated: 2022/03/14 15:23:55 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define ESC 53
# define W 13
# define D 2
# define S 1
# define A 0

typedef struct s_window
{
	void		*ptr;
	int			height;
	int			width;
}	t_window;

typedef struct s_map{
	int		width;
	int		height;
	char	**grid;
	int		walls;
	int		collectibles;
	int		space;
	int		exits;
	int		players;
	int		enemy;
	int		count;
}		t_map;

typedef struct s_vector
{
	int	x;
	int	y;	
}		t_vector;

typedef struct s_player
{
	t_vector		pos;
	unsigned int	step_count;
}		t_player;

typedef struct s_image{
	void		*ptr;
	t_vector	size;
	t_vector	pos;
	char		*pixels;
	int			bit_per_pixel;
	int			line_size;
	int			endian;
}		t_image;

typedef struct s_prog{
	void		*mlx;
	t_map		map;
	t_window	window;
	t_vector	sprite_pos;
	t_image		sprite;
	t_player	player;
}		t_prog;

char	*ft_itoa(int nb);

int		get_map_grid(t_prog *prog, char *file_name);
int		valid_name(char *file);
int		check_map_walls(char **grid, int height, int width);
int		main(int argc, char **argv);
int		ft_input(int keynum, t_prog *prog);
int		no_symb(t_map *map);

void	count_simbols(t_prog *prog, char simbol);
void	reset_map_counts(t_prog *prog);
void	fill_map_counts(t_prog *prog);
void	draw_map(t_prog *prog);
void	steps(t_prog *prog);
void	map_height_width(t_prog *prog, char *file_name);
void	player_move_right(t_prog *prog);
void	player_move_left(t_prog *prog);
void	player_move_up(t_prog *prog);
void	player_move_down(t_prog *prog);
void	draw_sprites_on_map(t_prog prog);
void	draw_map_ground(t_prog prog);
void	draw_sprite_ground(t_prog prog, int i, int j);
void	draw_sprite_wall(t_prog prog, int i, int j);
void	draw_sprite_collectibles(t_prog prog, int i, int j);
void	draw_sprite_exit(t_prog prog, int i, int j);
void	draw_sprite_player(t_prog prog, int i, int j, int anim_step);
void	draw_sprite_enemy(t_prog prog, int i, int j, int anim_step);
void	map_get_player_pos(t_prog *prog);
int		check_map_grid(t_prog *prog);
t_image	ft_new_sprite(void *mlx, char *path);
void	enemy_ground(t_prog *prog, int time, int i, int j);
int		animation_enemy(t_prog *prog, int time);
int		animation(t_prog *prog);
int		map_check_gameover(t_prog *prog, t_vector *pos);

# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*make_line(int fd, char *str);
char	*get_first_line(char *line);
char	*get_last_line(char *line);
char	*get_null(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		valid_name(char *file);

#endif