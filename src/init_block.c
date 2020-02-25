/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:17:03 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/14 16:17:30 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_block_shape(t_block *block)
{
	int		x;
	int		y;

	y = 0;
	block->start_x = block->x;
	block->start_y = block->y;
	while (y < block->y)
	{
		x = 0;
		while (x < block->x)
		{
			if (block->block[y][x] == '*')
			{
				block->start_x = x < block->start_x ? x : block->start_x;
				block->end_x = x > block->end_x ? x : block->end_x;
				block->start_y = y < block->start_y ? y : block->start_y;
				block->end_y = y > block->end_y ? y : block->end_y;
			}
			x++;
		}
		y++;
	}
	block->size_x = (block->end_x - block->start_x) + 1;
	block->size_y = (block->end_y - block->start_y) + 1;
}

void	init_block(t_block *block)
{
	char	*line;
	int		i;

	i = 0;
	if (block->block != NULL)
		free(block->block);
	if (!(block->block = (char**)malloc(sizeof(char*) * block->y + 1)))
		return ;
	while (i < block->y)
	{
		get_next_line(0, &line);
		block->block[i] = (char*)malloc(sizeof(char) * block->x + 1);
		block->block[i] = ft_strcpy(block->block[i], (const char *)line);
		i++;
		ft_strdel(&line);
	}
	get_block_shape(block);
}

void	get_block_size(t_block *block, char *str)
{
	int		i;

	i = 0;
	block->x = 0;
	block->y = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			if (block->y == 0)
			{
				block->y = ft_atoi(str + i);
				i += get_nbr_count(block->y);
			}
			else if (block->x == 0)
			{
				block->x = ft_atoi(str + i);
				i += get_nbr_count(block->x);
			}
		}
		i++;
	}
	ft_strdel(&str);
	init_block(block);
}
