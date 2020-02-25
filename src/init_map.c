/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:09:06 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/14 16:16:17 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_positions(t_map *map)
{
	int			x;
	static int	y;

	if (y == map->size_y)
		return ;
	y = 0;
	while (y < map->size_y)
	{
		x = -1;
		while (x++ < map->size_x)
		{
			if (map->map[y][x] == map->enemy[0] || map->map[y][x] ==
			map->enemy[1])
			{
				map->enemy_x = x;
				map->enemy_y = y;
			}
			if (map->map[y][x] == map->me[0] || map->map[y][x] == map->me[1])
			{
				map->my_x = x;
				map->my_y = y;
			}
		}
		y++;
	}
}

void	init_map(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	if (!(map->map = (char**)malloc(sizeof(char*) * map->size_y)))
		return ;
	while (i < map->size_y)
	{
		get_next_line(0, &line);
		map->map[i] = ft_strdup((const char *)&line[4]);
		ft_strdel(&line);
		i++;
	}
	get_positions(map);
}

void	map_size(t_map *map, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		while (line[i] >= 48 && line[i] <= 57)
		{
			if (map->size_y == 0)
			{
				map->size_y = ft_atoi(line + i);
				i += get_nbr_count(map->size_y);
			}
			else if (map->size_x == 0)
			{
				map->size_x = ft_atoi(line + i);
				i += get_nbr_count(map->size_x);
			}
			else
				i++;
		}
		i++;
	}
}

void	get_map(t_map *map, t_block *block)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			map_size(map, line);
			init_map(map);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			get_block_size(block, line);
			return ;
		}
		else
			ft_strdel(&line);
	}
}
