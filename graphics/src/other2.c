/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:30:22 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/24 15:32:29 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	fill_map_slots(t_info *info, int x, int y)
{
	if (info->map[y][x] == info->me || info->map[y][x]
	== info->me + 32 || info->map[y][x] == info->enemy ||
	info->map[y][x] == info->enemy + 32)
	{
		info->color = info->map[y][x] == info->me ||
		info->map[y][x] == info->me + 32 ? 0X6AA45A : 0XC46060;
		draw_block(info, init_list(x * (info->map_size +
		info->zoom), y * (info->map_size + info->zoom) + 1,
		(x + 1) * (info->map_size + info->zoom),
		y * (info->map_size + info->zoom) + 1), (y + 1) *
		(info->map_size + info->zoom) + 1);
		info->color = 0X000000;
	}
}

void	draw_x_y(t_info *info, int x, int y, int direction)
{
	if (direction == 1)
	{
		bresenham_algorithm(info, set_coords(info, init_list(x *
		(info->map_size + info->zoom), y * (info->map_size +
		info->zoom), (x + 1) * (info->map_size + info->zoom), y *
		(info->map_size + info->zoom))));
	}
	if (direction == 2)
	{
		bresenham_algorithm(info, set_coords(info, init_list(x *
		(info->map_size + info->zoom), y * (info->map_size +
		info->zoom), x * (info->map_size + info->zoom), (y + 1)
		* (info->map_size + info->zoom))));
	}
}

void	manage_speed(t_info *info, int speed)
{
	if (info->speed == 1 && info->my_score > 20)
		while (speed < 50000)
			speed++;
	else if (info->speed == 2)
		while (speed < 5000)
			speed++;
}
