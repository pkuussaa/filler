/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:35:03 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/24 16:19:11 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	get_score(t_info *info)
{
	int x;
	int y;

	info->en_score = 0;
	info->my_score = 0;
	y = 0;
	while (y < info->map_size_y)
	{
		x = 0;
		while (x < info->map_size_x)
		{
			if (info->map[y][x] == info->me || info->map[y][x] == info->me + 32)
				info->my_score++;
			else if (info->map[y][x] == info->enemy || info->map[y][x]
													== info->enemy + 32)
				info->en_score++;
			x++;
		}
		y++;
	}
}

void	init_map(t_info *info)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	if (!(info->map = (char**)malloc(sizeof(char*) * info->map_size_y + 1)))
		return ;
	while (i < info->map_size_y)
	{
		get_next_line(0, &line);
		info->map[i] = ft_strdup((const char *)&line[4]);
		ft_strdel(&line);
		i++;
	}
	info->map[i] = NULL;
	get_score(info);
}

void	map_size(t_info *info, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		while (line[i] >= 48 && line[i] <= 57)
		{
			if (info->map_size_y == 0)
			{
				info->map_size_y = ft_atoi(line + i);
				i += get_nbr_count(info->map_size_y);
			}
			else if (info->map_size_x == 0)
			{
				info->map_size_x = ft_atoi(line + i);
				i += get_nbr_count(info->map_size_x);
			}
			else
				i++;
		}
		i++;
	}
	info->map_size = 200 / (get_nbr_count(info->map_size_x +
	info->map_size_y) * 8);
}

int		get_map(t_info *info)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			map_size(info, line);
			init_map(info);
			ft_strdel(&line);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}

void	get_player(t_info *info)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "$$$ exec p1 : [./pkuussaa.filler]") == 0)
		{
			info->me = 'O';
			info->enemy = 'X';
			ft_strdel(&line);
			return ;
		}
		else if (ft_strcmp(line, "$$$ exec p2 : [./pkuussaa.filler]") == 0)
		{
			info->me = 'X';
			info->enemy = 'O';
			ft_strdel(&line);
			return ;
		}
		ft_strdel(&line);
	}
}
