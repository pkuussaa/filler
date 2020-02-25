/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:40:09 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/24 17:08:01 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

int		key_press(int keycode, void *param)
{
	t_info *info;

	info = param;
	if (keycode == 53)
		exit(0);
	if (keycode == 35)
		info->pause = info->pause == 1 ? 0 : 1;
	if (keycode == 49)
		info->automatic = info->automatic == 1 ? 0 : 1;
	if (info->automatic == 0 && keycode == 49)
		if (get_map(info) == 1)
			re_draw(info);
	if (keycode == 24 && info->speed < 3 && info->automatic == 1)
		info->speed++;
	if (keycode == 27 && info->speed > 1 && info->automatic == 1)
		info->speed--;
	return (0);
}

void	zoom_and_end(t_info *info, int value)
{
	if (value == 1)
	{
		system("make run");
		exit(0);
	}
	if (value == 2)
		exit(0);
	if (value == 3)
		if (get_map(info) == 1)
		{
			info->zoom += 3;
			re_draw(info);
			if (info->pause == 0)
				mlx_string_put(info->mlx, info->win, 1230, 675, 0XE7A23D,
				"PAUSED");
		}
	if (value == 4)
		if (get_map(info) == 1)
		{
			info->zoom -= 3;
			re_draw(info);
			if (info->pause == 0)
				mlx_string_put(info->mlx, info->win, 1230, 675, 0XE7A23D,
				"PAUSED");
		}
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_info *info;

	info = param;
	if (button == 1 && info->automatic == 0)
	{
		if (get_map(info) == 1)
			re_draw(info);
		else
		{
			if (x >= 975 && x <= 1175 && y >= 650 && y <= 720)
				zoom_and_end(info, 1);
			if (x >= 1375 && x <= 1575 && y >= 650 && y <= 720)
				zoom_and_end(info, 2);
		}
	}
	if (button == 4)
		if (info->zoom < 4)
			zoom_and_end(info, 3);
	if (button == 5)
		if (info->zoom > -6)
			zoom_and_end(info, 4);
	return (0);
}

void	manage_result(t_info *info)
{
	int i;

	i = 0;
	while (i < 200000000)
		i++;
	info->end = 1;
	mlx_put_image_to_window(info->mlx, info->win, info->img2, 850, 450);
	info->my_score > info->en_score ? mlx_string_put(info->mlx,
	info->win, 1200, 575, 0XFFFFFF, "Y O U    W O N !") :
	mlx_string_put(info->mlx, info->win, 1200, 575, 0XFFFFFF,
	"Y O U    L O S T !");
	draw_end_box(info);
	mlx_string_put(info->mlx, info->win, 1020, 675, 0XFFFFFF, "PLAY AGAIN");
	mlx_string_put(info->mlx, info->win, 1455, 675, 0XFFFFFF, "QUIT");
	info->automatic = 0;
}

int		handle_loop(void *params)
{
	t_info	*info;
	int		i;

	i = 0;
	info = (t_info*)params;
	mlx_hook(info->win, 4, 0, mouse_press, info);
	if (info->pause == 1)
	{
		if (info->automatic == 1)
		{
			if (get_map(info) == 1)
				re_draw(info);
			else if (info->end == 0)
				manage_result(info);
		}
	}
	else if (info->pause == 0)
		mlx_string_put(info->mlx, info->win, 1230, 675, 0XE7A23D, "PAUSED");
	return (0);
}
