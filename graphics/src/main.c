/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:01:03 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/24 16:19:55 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	free_map(t_info *info)
{
	int i;

	i = 0;
	while (info->map[i])
	{
		ft_strdel(&info->map[i]);
		i++;
	}
	free(info->map);
}

void	re_draw(t_info *info)
{
	mlx_clear_window(info->mlx, info->win);
	draw_map(info);
	draw_score_bar(info, 200);
	free_map(info);
	interface(info);
}

void	init_start_values(t_info *info)
{
	info->zoom = 0;
	info->pause = 1;
	info->speed = 3;
	info->end = 0;
	info->automatic = 1;
	info->map_size_x = 0;
	info->map_size_y = 0;
}

int		main(void)
{
	t_info *info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	init_start_values(info);
	info->mlx = mlx_init();
	get_player(info);
	get_map(info);
	info->win = mlx_new_window(info->mlx, 2550, 1350, "Filler");
	info->img = mlx_new_image(info->mlx, 2550, 1350);
	info->data_addr = mlx_get_data_addr(info->img, &(info->bits_per_pixel),
				&(info->size_line), &(info->endian));
	info->img2 = mlx_new_image(info->mlx, 850, 450);
	info->data_addr2 = mlx_get_data_addr(info->img2, &(info->bits_per_pixel2),
				&(info->size_line2), &(info->endian2));
	draw_background(info);
	end_screen(info);
	draw_map(info);
	interface(info);
	draw_score_bar(info, 200);
	free_map(info);
	mlx_hook(info->win, 2, 0, key_press, info);
	mlx_loop_hook(info->mlx, handle_loop, info);
	mlx_loop(info->mlx);
}
