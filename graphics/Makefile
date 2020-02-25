# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 17:57:55 by pkuussaa          #+#    #+#              #
#    Updated: 2020/02/24 15:34:38 by pkuussaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = graphics

SRC = src/main.c src/draw.c src/draw2.c src/other.c src/other2.c src/get_nbr_count.c src/interface.c src/get_map_info.c src/actions.c ../Libft/libft.a ../get_next_line/get_next_line.c

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

INCLUDE = -I ./includes/graphics.h

.PHONY: all clean fclean re

all: $(FILE)

$(FILE):
	gcc $(FLAGS) $(INCLUDE) -o $(FILE) $(SRC)

clean:

fclean: clean
	rm -f $(FILE)

re : fclean all
