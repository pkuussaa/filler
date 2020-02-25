/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:25:47 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/14 18:00:12 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

typedef	struct	s_map
{
	char		**map;
	int			player;
	int			size_y;
	int			size_x;
	int			enemy_x;
	int			enemy_y;
	int			my_x;
	int			my_y;
	int			contact;
	char		*enemy;
	char		*me;
}				t_map;

typedef	struct	s_block
{
	char		**block;
	int			x;
	int			y;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	int			size_x;
	int			size_y;
	int			res_x;
	int			res_y;
	int			tmp_x;
	int			tmp_y;
}				t_block;

int				get_nbr_count(intmax_t len);
int				algorithm(t_map *map, t_block *block);
int				check_fit(t_map *map, t_block *block, int x2, int y2);
int				block_enemy(t_map *map, t_block *block);
int				reach_contact2(t_map *map, t_block *block);
int				reach_contact1(t_map *map, t_block *block);
int				reach_contact3(t_map *map, t_block *block);
int				reach_contact4(t_map *map, t_block *block);

void			place_block(t_map *map, t_block *block);
void			get_map(t_map *map, t_block *block);
void			get_block_size(t_block *block, char *str);
#endif
