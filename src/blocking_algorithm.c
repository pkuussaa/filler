/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocking_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:39:03 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/14 16:52:47 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	contact_count(t_map *map, int count, int x, int y)
{
	if (map->map[y][x + count] == map->enemy[0] ||
		map->map[y][x - count] == map->enemy[0] ||
		map->map[y + count][x] == map->enemy[0] ||
		map->map[y - count][x] == map->enemy[0] ||
		map->map[y][x + count] == map->enemy[1] ||
		map->map[y][x - count] == map->enemy[1] ||
		map->map[y + count][x] == map->enemy[1] ||
		map->map[y - count][x] == map->enemy[1])
		map->contact += (4 - count);
}

void	count_contact(t_map *map, t_block *block, int x2, int y2)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	map->contact = 0;
	while (y < block->y)
	{
		x = -1;
		while (++x < block->x)
			if (block->block[y][x] == '*')
			{
				count = 1;
				while (count < 4)
				{
					if ((x + x2 + count) < map->size_x && (x + x2 - count) > 0
					&& (y + y2 + count) < map->size_y && (y + y2 - count) > 0)
						contact_count(map, count, x + x2, y + y2);
					count++;
				}
			}
		y++;
	}
}

int		block_enemy_return(t_map *map, t_block *block, int contact_count)
{
	if (contact_count == -1)
		return (1);
	block->res_x = block->tmp_x;
	block->res_y = block->tmp_y;
	place_block(map, block);
	return (0);
}

int		block_enemy(t_map *map, t_block *block)
{
	int		x;
	int		y;
	int		contact_count;

	contact_count = -1;
	y = map->size_y;
	block->tmp_x = 0;
	block->tmp_y = 0;
	while (--y >= 0)
	{
		x = map->size_x;
		while (--x >= 0)
			if (check_fit(map, block, x, y) == 1)
			{
				count_contact(map, block, x, y);
				if (map->contact > contact_count)
				{
					contact_count = map->contact;
					block->tmp_x = x;
					block->tmp_y = y;
				}
			}
	}
	return (block_enemy_return(map, block, contact_count));
}
