/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:14:42 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/24 16:16:02 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	line_high(t_info *info, double *arr)
{
	double	x;
	double	y;
	int		check;
	double	d;

	x = arr[2] - arr[0];
	y = arr[3] - arr[1];
	check = x < 0 ? -1 : 1;
	if (x < 0)
		x = -x;
	d = 2 * x - y;
	while (arr[1] < arr[3])
	{
		mlx_pixel_put(info->mlx, info->win, arr[0] + 2550 / 2,
		arr[1] + 1350 / 2, info->color);
		if (d > 0)
		{
			arr[0] += check;
			d -= 2 * y;
		}
		d += 2 * x;
		arr[1]++;
	}
	free(arr);
}

void	line_low(t_info *info, double *arr)
{
	double	x;
	double	y;
	int		check;
	double	d;

	x = arr[2] - arr[0];
	y = arr[3] - arr[1];
	check = y < 0 ? -1 : 1;
	if (y < 0)
		y = -y;
	d = (2 * y) - x;
	while (arr[0] < arr[2])
	{
		mlx_pixel_put(info->mlx, info->win, arr[0] + 2550 / 2,
		arr[1] + 1350 / 2, info->color);
		if (d > 0)
		{
			arr[1] += check;
			d -= 2 * x;
		}
		d += 2 * y;
		arr[0]++;
	}
	free(arr);
}

void	bresenham_algorithm(t_info *info, double *arr)
{
	double	y_abs;
	double	x_abs;

	y_abs = arr[3] - arr[1] > 0 ? arr[3] - arr[1] : (arr[3] - arr[1]) * -1;
	x_abs = arr[2] - arr[0] > 0 ? arr[2] - arr[0] : -(arr[2] - arr[0]);
	if (y_abs < x_abs)
	{
		if (arr[0] > arr[2])
			line_low(info, init_list(arr[2], arr[3], arr[0], arr[1]));
		else
			line_low(info, init_list(arr[0], arr[1], arr[2], arr[3]));
	}
	else
	{
		if (arr[1] > arr[3])
			line_high(info, init_list(arr[2], arr[3], arr[0], arr[1]));
		else
			line_high(info, init_list(arr[0], arr[1], arr[2], arr[3]));
	}
	free(arr);
}

void	draw_block(t_info *info, double *arr, int end)
{
	int y;

	y = arr[1];
	while (y < end)
	{
		bresenham_algorithm(info, set_coords(info,
		init_list(arr[0], arr[1], arr[2], arr[3])));
		arr[3] += 1;
		arr[1] += 1;
		y++;
	}
	free(arr);
}

void	draw_map(t_info *info)
{
	int y;
	int x;

	y = 0;
	info->color = 0X000000;
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	while (y <= info->map_size_y)
	{
		x = 0;
		while (x <= info->map_size_x)
		{
			if (x < info->map_size_x)
			{
				manage_speed(info, 0);
				draw_x_y(info, x, y, 1);
				if (x < info->map_size_x && y < info->map_size_y)
					fill_map_slots(info, x, y);
			}
			if (y < info->map_size_y)
				draw_x_y(info, x, y, 2);
			x++;
		}
		y++;
	}
}
