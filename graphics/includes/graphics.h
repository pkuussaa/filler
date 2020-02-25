/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:58:00 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/24 15:35:23 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../../get_next_line/get_next_line.h"
# include "../../Libft/libft.h"
# include "../../ft_printf/includes/ft_printf.h"
# include "mlx.h"

typedef	struct	s_info
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bits_per_pixel;
	char		*data_addr;
	int			size_line;
	int			endian;
	void		*img2;
	int			bits_per_pixel2;
	char		*data_addr2;
	int			size_line2;
	int			endian2;
	int			map_size_y;
	int			map_size_x;
	int			en_score;
	int			my_score;
	int			end;
	int			pause;
	int			zoom;
	char		me;
	char		enemy;
	int			map_size;
	int			color;
	int			automatic;
	int			speed;
	char		**map;
}				t_info;

void			re_draw(t_info *info);
void			draw_map(t_info *info);
void			draw_background(t_info *info);
void			draw_score_bar(t_info *info, double size);
void			end_screen(t_info *info);
void			draw_end_box(t_info *info);
void			get_player(t_info *info);
void			interface(t_info *info);
void			score_bar(t_info *info, double *arr);
void			put_box_pixel(t_info *info, int x, int y);
void			put_result_pixels(t_info *info, int x, int y);
void			fill_map_slots(t_info *info, int x, int y);
void			draw_x_y(t_info *info, int x, int y, int direction);
void			manage_speed(t_info *info, int speed);
void			draw_block(t_info *info, double *arr, int end);
void			bresenham_algorithm(t_info *info, double *arr);

int				key_press(int keycode, void *param);
int				mouse_press(int button, int x, int y, void *param);
int				handle_loop(void *params);
int				key_press(int keycode, void *param);
int				get_nbr_count(intmax_t len);
int				get_map(t_info *info);

double			*set_coords(t_info *info, double *arr);
double			*init_list(double start_x, double start_y,
								double end_x, double end_y);

#endif
