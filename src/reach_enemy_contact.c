/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_enemy_contact.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:19:48 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/14 16:20:40 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		reach_contact1(t_map *map, t_block *block)
{
	int		x;
	int		y;

	y = map->size_y - 1;
	while (y > 0)
	{
		x = map->size_x;
		while (x >= 0)
		{
			if (check_fit(map, block, x, y) == 1)
			{
				place_block(map, block);
				return (0);
			}
			x--;
		}
		y--;
	}
	return (1);
}

int		reach_contact3(t_map *map, t_block *block)
{
	int		x;
	int		y;

	y = map->size_y - 1;
	while (y > 0)
	{
		x = 0;
		while (x < map->size_x - 1)
		{
			if (check_fit(map, block, x, y) == 1)
			{
				place_block(map, block);
				return (0);
			}
			x++;
		}
		y--;
	}
	return (1);
}

int		reach_contact2(t_map *map, t_block *block)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->size_y - 1)
	{
		x = 0;
		while (x < map->size_x - 1)
		{
			if (check_fit(map, block, x, y) == 1)
			{
				place_block(map, block);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int		reach_contact4(t_map *map, t_block *block)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->size_y - 1)
	{
		x = map->size_x - 1;
		while (x >= 0)
		{
			if (check_fit(map, block, x, y) == 1)
			{
				place_block(map, block);
				return (0);
			}
			x--;
		}
		y++;
	}
	return (1);
}
