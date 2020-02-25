/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:59:03 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/24 16:04:46 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	draw_end_box(t_info *info)
{
	int x;
	int y;
	int count;

	x = 0;
	count = 0;
	y = 0;
	while (count < 2)
	{
		put_result_pixels(info, x, y);
		x++;
		y++;
		if (x == 201)
		{
			count++;
			x = 0;
		}
		if (y == 70)
			y = 0;
	}
}

void	draw_box(t_info *info)
{
	int x;
	int y;
	int count;

	x = 0;
	count = 0;
	y = 0;
	while (count < 2)
	{
		put_box_pixel(info, x, y);
		x++;
		y++;
		if (x == 201)
		{
			count++;
			x = 0;
		}
		if (y == 20)
			y = 0;
	}
}

void	draw_score_bar(t_info *info, double size)
{
	double *arr;
	double max_size;

	arr = (double*)malloc(sizeof(double) * 4);
	max_size = info->map_size_y * info->map_size_x;
	arr[2] = ((double)info->my_score / max_size) * 100;
	arr[2] = (arr[2] / 100) * size;
	arr[3] = ((double)info->en_score / max_size) * 100;
	arr[3] = (arr[3] / 100) * size;
	arr[1] = 0;
	arr[0] = 0;
	while (arr[0] < 200)
	{
		score_bar(info, arr);
		arr[1]++;
		if (arr[1] == 20)
		{
			arr[1] = 0;
			arr[0]++;
		}
	}
	free(arr);
	draw_box(info);
}

void	end_screen(t_info *info)
{
	int *image;
	int i;

	info->color = 0X000000;
	ft_bzero(info->data_addr2, 850 * 450 * (info->bits_per_pixel2 / 8));
	image = (int*)(info->data_addr2);
	i = 0;
	while (i < 850 * 450)
	{
		if (i <= 8500 || i >= 374000 || i % 850 <= 10 || i % 850 >= 840)
			image[i] = 0X3E3434;
		else
			image[i] = info->color;
		i++;
	}
}

void	draw_background(t_info *info)
{
	int *image;
	int i;

	info->color = 0X6E6969;
	ft_bzero(info->data_addr, 2550 * 1350 * (info->bits_per_pixel / 8));
	image = (int*)(info->data_addr);
	i = 0;
	while (i < 2550 * 1350)
	{
		image[i] = (i % 2550 < 500) ? 0X494141 : info->color;
		if (i % 2550 > 500)
		{
			image[i] = (i % 2550 > 2100) ? 0X494141 : info->color;
			if (i > (2550 * 1350) / 2)
				image[i] = (i % 2550 > 2100) ? 0X180D0D : info->color;
		}
		i++;
	}
	info->color = 0X000000;
}
