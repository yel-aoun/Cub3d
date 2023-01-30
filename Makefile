# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 08:13:34 by yel-aoun          #+#    #+#              #
#    Updated: 2023/01/30 14:30:21 by yel-aoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
# NAME_BONUS = cub3d_bonus

SRCS = main.c cub3d.c creat_map.c ft_move.c \
	ft_cub3d_help.c calculation_drawing.c get_next_line.c \
	get_next_line_utils.c split.c ft_strchr.c ft_strtrim.c ft_strncmp.c \
	ft_strdup.c ft_atoi.c norm1.c norm2.c norm3.c norm4.c norm5.c

CC = gcc

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS =   -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -fsanitize=address

all: $(NAME)

%.o: %.c
	$(CC) $(GFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(SRCS)  $(MLX_FLAGS) -o $(NAME) 
 
clean:
	rm -f $(OBJS)
	# rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	# rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re 