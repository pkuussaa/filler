/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:01:13 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/24 15:14:57 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

double	*set_coords(t_info *info, double *arr)
{
	(void)info;
	arr[0] -= (info->map_size_x * (info->map_size + info->zoom)) / 2;
	arr[1] -= (info->map_size_y * (info->map_size + info->zoom)) / 2;
	arr[2] -= (info->map_size_x * (info->map_size + info->zoom)) / 2;
	arr[3] -= (info->map_size_y * (info->map_size + info->zoom)) / 2;
	return (arr);
}

double	*init_list(double start_x, double start_y, double end_x,
													double end_y)
{
	double *arr;

	if (!(arr = (double *)malloc(sizeof(double) * 4)))
		return (0);
	arr[0] = start_x;
	arr[1] = start_y;
	arr[2] = end_x;
	arr[3] = end_y;
	return (arr);
}

void	score_bar(t_info *info, double *arr)
{
	arr[0] <= arr[2] ? mlx_pixel_put(info->mlx, info->win, arr[0] + 150,
	arr[1] + 350, 0X47B2F3) :
	mlx_pixel_put(info->mlx, info->win, arr[0] + 150, arr[1] + 350,
	0X2589BC);
	arr[0] <= arr[3] ? mlx_pixel_put(info->mlx, info->win, arr[0] + 150,
	arr[1] + 450, 0XF14444) :
	mlx_pixel_put(info->mlx, info->win, arr[0] + 150, arr[1] + 450,
	0XC43232);
}

void	put_box_pixel(t_info *info, int x, int y)
{
	mlx_pixel_put(info->mlx, info->win, x + 149, 349, 0X000000);
	mlx_pixel_put(info->mlx, info->win, x + 149, 370, 0X000000);
	mlx_pixel_put(info->mlx, info->win, x + 149, 449, 0X000000);
	mlx_pixel_put(info->mlx, info->win, x + 149, 470, 0X000000);
	mlx_pixel_put(info->mlx, info->win, 149, y + 350, 0X000000);
	mlx_pixel_put(info->mlx, info->win, 349, y + 350, 0X000000);
	mlx_pixel_put(info->mlx, info->win, 149, y + 450, 0X000000);
	mlx_pixel_put(info->mlx, info->win, 349, y + 450, 0X000000);
}

void	put_result_pixels(t_info *info, int x, int y)
{
	mlx_pixel_put(info->mlx, info->win, x + 975, 649, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->win, x + 975, 720, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->win, x + 1375, 649, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->win, x + 1375, 720, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->win, 975, y + 650, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->win, 1175, y + 650, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->win, 1375, y + 650, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->win, 1575, y + 650, 0XFFFFFF);
}
