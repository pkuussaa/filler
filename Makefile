# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/07 14:22:42 by pkuussaa          #+#    #+#              #
#    Updated: 2020/02/24 17:08:46 by pkuussaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = pkuussaa.filler

SRC = src/main.c src/init_map.c src/init_block.c src/reach_enemy_contact.c src/blocking_algorithm.c src/algorithm.c get_next_line/get_next_line.c Libft/libft.a src/get_nbr_count.c ft_printf/libftprintf.a

INC = includes/fller.h

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re run

all: $(FILE)

$(FILE):
	@echo "Compiling..."
	@cd Libft && make && cd ..
	@cd graphics && make re && cd ..
	gcc -I $(INC) -o $(FILE) $(SRC)
	@echo "Done."

clean:
	@echo "cleaning libraries..."
	@cd Libft && make clean && cd ..
	@rm -f filler.trace

fclean: clean
	@echo "removing executables..."
	@cd Libft && make fclean && cd ..
	@cd graphics && make fclean && cd ..
	@rm -f pkuussaa.filler

re: fclean all

run :
	./resources/./filler_vm -f resources/maps/map02 -p1 ./pkuussaa.filler -p2 resources/players/abanlin.filler | graphics/./graphics

