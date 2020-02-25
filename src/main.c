/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:47:44 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/24 14:20:05 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			place_block(t_map *map, t_block *block)
{
	ft_printf("%d %d\n", block->res_y, block->res_x);
	map->my_x = block->res_x;
	map->my_y = block->res_y;
}

static	void	get_player(t_map *map)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "$$$ exec p1 : [./pkuussaa.filler]") == 0)
		{
			map->player = 1;
			map->me = ft_strdup("Oo");
			map->enemy = ft_strdup("Xx");
			return ;
		}
		else if (ft_strcmp(line, "$$$ exec p2 : [./pkuussaa.filler]") == 0)
		{
			map->player = 2;
			map->enemy = ft_strdup("Oo");
			map->me = ft_strdup("Xx");
			return ;
		}
	}
}

void			initialize(t_map *map, t_block *block)
{
	map->map = NULL;
	map->player = 0;
	map->size_y = 0;
	map->size_x = 0;
	map->enemy_x = 0;
	map->enemy_y = 0;
	map->my_x = 0;
	map->my_y = 0;
	map->contact = 0;
	block->block = NULL;
	block->x = 0;
	block->y = 0;
	block->start_x = 0;
	block->start_y = 0;
	block->end_y = 0;
	block->end_x = 0;
	block->size_y = 0;
	block->size_x = 0;
	block->res_x = 0;
	block->res_y = 0;
}

int				main(void)
{
	t_map	*map;
	t_block	*block;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (0);
	if (!(block = (t_block*)malloc(sizeof(t_block))))
		return (0);
	initialize(map, block);
	get_player(map);
	while (1)
	{
		get_map(map, block);
		if (algorithm(map, block) == 1)
		{
			if (reach_contact2(map, block) == 1)
			{
				place_block(map, block);
				break ;
			}
		}
		free(map->map);
	}
	free(block);
	free(map);
	return (0);
}
