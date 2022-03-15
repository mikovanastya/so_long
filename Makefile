# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 16:01:15 by rtwitch           #+#    #+#              #
#    Updated: 2022/03/14 14:49:51 by rtwitch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long
NAME_B 	= so_long_bonus

SRCS = so_long.c \
		check_map.c \
		ft_input.c \
		get_next_line.c \
		get_next_line_utils.c \
		player.c \
		draw_map.c\
		image.c \
		utils.c \
		sprites.c \
		check_map_utils.c

SRCS_B = bonus/so_long_bonus.c \
		bonus/check_map_bonus.c \
		bonus/ft_input_bonus.c \
		bonus/get_next_line_bonus.c \
		bonus/get_next_line_utils_bonus.c \
		bonus/player_bonus.c \
		bonus/draw_map_bonus.c\
		bonus/image_bonus.c \
		bonus/utils_bonus.c \
		bonus/sprites_bonus.c \
		bonus/check_map_utils_bonus.c \
		bonus/animation_bonus.c

HEADER = so_long.h
HEADER_B = so_long_bonus.h

OBJ 	= $(SRCS:.c=.o)
OBJ_B 	= $(SRCS_B:.c=.o)


FLAGS = -Wall -Wextra -Werror -I.
		
all : $(NAME) 

bonus : $(NAME_B)

$(NAME) : $(OBJ)
	gcc $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

$(NAME_B) : $(OBJ_B)
	gcc $(OBJ_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)
	
%.o : %.c $(HEADER) $(HEADER_B)
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ) $(OBJ_B)

fclean : clean
	rm -rf $(NAME) $(NAME_B)
	

re : fclean all

.PHONY : all clean fclean re bonus