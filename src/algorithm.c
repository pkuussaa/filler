/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:53:38 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/14 17:17:19 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		check_fit_return(t_block *block, int check, int x2, int y2)
{
	if (check == 1)
	{
		block->res_x = x2;
		block->res_y = y2;
		return (1);
	}
	return (0);
}

int		check_fit(t_map *map, t_block *block, int x2, int y2)
{
	int		x;
	int		y;
	int		check;

	y = 0;
	if (y2 + block->y > map->size_y || x2 + block->x > map->size_x)
		return (0);
	check = 0;
	while (y < block->y)
	{
		x = 0;
		while (x < block->x)
		{
			if (block->block[y][x] == '*' && (map->map[y2 + y][x2 + x] ==
			map->enemy[0] || map->map[y2 + y][x2 + x] == map->enemy[1]))
				return (0);
			if (block->block[y][x] == '*' && (map->map[y2 + y][x2 + x] ==
			map->me[0] || map->map[y2 + y][x2 + x] == map->me[1]))
				check++;
			x++;
		}
		y++;
	}
	return (check_fit_return(block, check, x2, y2));
}

int		check_enemy_contact(t_map *map, t_block *block)
{
	int	x;
	int	y;

	y = 3;
	if (map->size_x < 7 || map->size_y < 7)
		return (0);
	while (y < map->size_y - 3)
	{
		x = 3;
		while (x < map->size_x - 3)
		{
			if (map->map[y][x] == map->me[0] || map->map[y][x] == map->me[1])
				if (map->map[y][x + 3] == map->enemy[0] || map->map[y][x + 3] ==
				map->enemy[1] || map->map[y][x - 3] == map->enemy[0] ||
				map->map[y][x - 3] == map->enemy[1] || map->map[y + 3][x] ==
				map->enemy[0] || map->map[y + 3][x] == map->enemy[1] ||
				map->map[y - 3][x] == map->enemy[0] || map->map[y - 3][x] ==
				map->enemy[1])
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int		get_direction(t_map *map, t_block *block, int direction)
{
	if (direction == 1)
	{
		if (map->my_x < map->enemy_x)
			return (reach_contact1(map, block));
		else
			return (reach_contact3(map, block));
	}
	else if (direction == 2)
	{
		if (map->my_x > map->enemy_x)
			return (reach_contact2(map, block));
		else
			return (reach_contact4(map, block));
	}
	return (0);
}

int		algorithm(t_map *map, t_block *block)
{
	if (check_enemy_contact(map, block) == 0)
	{
		if (map->my_y < map->enemy_y)
			return (get_direction(map, block, 1));
		else if (map->my_y >= map->enemy_y)
			return (get_direction(map, block, 2));
	}
	else
		return (block_enemy(map, block));
	return (0);
}
