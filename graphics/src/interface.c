/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:51:35 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/24 14:55:21 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	output_controls(t_info *info)
{
	mlx_string_put(info->mlx, info->win, 2240, 800, 0XFFFFFF, "CONTROLS");
	mlx_string_put(info->mlx, info->win, 2170, 870, 0XFFFFFF,
	"Change mode : Space");
	mlx_string_put(info->mlx, info->win, 2170, 910, 0XFFFFFF,
	"Change speed : + , -");
	mlx_string_put(info->mlx, info->win, 2170, 960, 0XFFFFFF,
	"Zoom : Mouse scroll");
	mlx_string_put(info->mlx, info->win, 2170, 1000, 0XFFFFFF,
	"Pause in automatic mode : P");
	mlx_string_put(info->mlx, info->win, 2170, 1050, 0XFFFFFF,
	"next move in manual mode : Mouse left");
	mlx_string_put(info->mlx, info->win, 2490, 1070, 0XFFFFFF, "click");
	mlx_string_put(info->mlx, info->win, 2170, 1100, 0XFFFFFF, "Quit : ESC");
}

void	interface2(t_info *info, char *str, char *itoa)
{
	char *tmp;

	itoa = ft_itoa(info->en_score);
	str = ft_strjoin("Enemy score: ", itoa);
	mlx_string_put(info->mlx, info->win, 150, 400, 0XC6C2C2, str);
	free(itoa);
	free(str);
	itoa = ft_itoa(info->speed);
	tmp = ft_strjoin("Speed: ", itoa);
	free(itoa);
	str = ft_strjoin(tmp, "x");
	free(tmp);
	mlx_string_put(info->mlx, info->win, 2240, 200, 0XC6C2C2, str);
	free(str);
	str = info->automatic == 1 ? ft_strdup("MODE: Automatic") :
	ft_strdup("MODE: Manual");
	mlx_string_put(info->mlx, info->win, 2240, 300, 0XC6C2C2, str);
	free(str);
}

void	interface(t_info *info)
{
	char *str;
	char *itoa;

	str = ft_strdup("*****************");
	mlx_string_put(info->mlx, info->win, 150, 80, 0XC6C2C2, str);
	free(str);
	str = ft_strdup("F   L   E");
	mlx_string_put(info->mlx, info->win, 180, 100, 0XC6C2C2, str);
	free(str);
	str = ft_strdup("I   L   R");
	mlx_string_put(info->mlx, info->win, 200, 105, 0XC6C2C2, str);
	free(str);
	str = ft_strdup("*****************");
	mlx_string_put(info->mlx, info->win, 150, 125, 0XC6C2C2, str);
	free(str);
	itoa = ft_itoa(info->my_score);
	str = ft_strjoin("My score: ", itoa);
	mlx_string_put(info->mlx, info->win, 150, 300, 0XC6C2C2, str);
	free(itoa);
	free(str);
	interface2(info, str, itoa);
	output_controls(info);
}
