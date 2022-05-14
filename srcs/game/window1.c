/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:46:37 by esylva            #+#    #+#             */
/*   Updated: 2022/05/12 19:45:14 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_win_init(t_data *data)
{
	data->window->mlx_ptr = mlx_init();
	if (!data->bonus)
		data->window->win_ptr = mlx_new_window(data->window->mlx_ptr,
			W_PANEL, H_PANEL, "cub3D without bonuses");
	else
		data->window->win_ptr = mlx_new_window(data->window->mlx_ptr,
			W_PANEL, H_PANEL, "CUB3D with BONUSES!");
	data->window->img = mlx_new_image(data->window->mlx_ptr, W_PANEL, H_PANEL);
	data->window->addr = mlx_get_data_addr(data->window->img,
		&data->window->bits_per_pixel, &data->window->line_length,
		&data->window->endian);
	ft_img_init(data);
	return (0);
}

void	ft_paint(t_data *data)
{
	mlx_clear_window(data->window->mlx_ptr, data->window->win_ptr);
	if (!data->bonus)
		ft_back(data);
	else
		ft_back_bonus(data);
	ft_cast_rays(data, '1');
	ft_cast_rays(data, 'L');
	if (data->bonus)
		ft_put_minimap(data);	
	 mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, data->window->img, 0, 0);
}

void	ft_draw_(t_data *data, double x, double y, int color)
{
	double	i;
	double	j;

	i = x;
	j = y;
	// data->window->addr = mlx_get_data_addr(data->window->img, &data->window->bits_per_pixel, &data->window->line_length, &data->window->endian);
	while (i <= x + ONE_SIZE)
	{
		while (j <= y + ONE_SIZE)
		{
			my_mlx_pixel_put(data, (int)i + (x  * ONE_SIZE), (int)(j + y * ONE_SIZE), color);
			j++;
		}
		j =  y;
		i++;
	}
	// mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, data->window->img, 0, 0);
}

// void	ft_draw_player(t_data *data, int color)
// {
// 	my_mlx_pixel_put(data, (int)(data->player->pos_x * ONE_SIZE),
// 		(int)(data->player->pos_y * ONE_SIZE), color);
// 	// ft_cast_rays(data, color, '1');
// 	ft_cast_rays(data, '1');
// }

void	ft_draw_2D_woll(t_data *data)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	// printf("x = %d %d, y = %d %d\n", data->map->x, data->map->size_x, data->map->y, data->map->size_y);
	while(j < data->map->size_y)
	{
		while (i < data->map->size_x)
		{
			if (data->map->coord[j][i] == '1')
			ft_draw_(data, i, j, WOLL);
			i++;
		}
		j++;
		i = 0;
	}
}

int	key_kb_hook(int keycode, t_data *data)
{
	if (keycode == GO_FORWARD)
		ft_go_forward(data);
	else if (keycode == STR_LEFT)
		ft_str_left(data);
	else if (keycode == GO_BACKWARD)
		ft_go_backward(data);
	else if (keycode == STR_RIGHT)
		ft_str_right(data);
	else if (keycode == TURN_RIGHT)
		ft_turn_right(data);
	else if (keycode == TURN_LEFT)
		ft_turn_left(data);
	else if (keycode == USE)
		ft_open_door(data);

printf("keycode = %d\n", keycode);
	if (keycode == EXIT)
	{
		mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
		ft_exit(data, 0);
	}
	return (keycode);
}


void	ft_img_init(t_data *data)
{
	if (data->bonus)
		ft_img_bonus_init(data);
	data->north->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
		data->north->loc, &data->north->size_x, &data->north->size_y);
	data->north->addr = mlx_get_data_addr(data->north->image,
		&data->north->bitpp, &data->north->line, &data->north->endian);
	data->south->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
		data->south->loc, &data->south->size_x, &data->south->size_y);
	data->south->addr = mlx_get_data_addr(data->south->image,
		&data->south->bitpp, &data->south->line, &data->south->endian);
	data->west->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
		data->west->loc, &data->west->size_x, &data->west->size_y);
	data->west->addr = mlx_get_data_addr(data->west->image,
		&data->west->bitpp, &data->west->line, &data->west->endian);
	data->east->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
		data->east->loc, &data->east->size_x, &data->east->size_y);
	data->east->addr = mlx_get_data_addr(data->east->image,
		&data->east->bitpp, &data->east->line, &data->east->endian);
}

void	ft_img_bonus_init(t_data *data)
	{
		data->ground->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
			data->ground->loc, &data->ground->size_x, &data->ground->size_y);
		data->ground->addr = mlx_get_data_addr(data->ground->image,
			&data->ground->bitpp, &data->ground->line, &data->ground->endian);
		data->cloud->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
			data->cloud->loc, &data->cloud->size_x, &data->cloud->size_y);
		data->cloud->addr = mlx_get_data_addr(data->cloud->image,
			&data->cloud->bitpp, &data->cloud->line, &data->cloud->endian);
		
		data->door = ft_init_image(data->door);
		if (!data->door)
			exit(1);
		data->door->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
			"img/walls/eagle.xpm", &data->door->size_x, &data->door->size_y);
		data->door->addr = mlx_get_data_addr(data->door->image,
			&data->door->bitpp, &data->door->line, &data->door->endian);
		// data->door = ft_init_image(data->door);
		// if (!data->door)
		// 	exit(6);
		// data->door->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
		// 	"img/eagle.xpm", &data->door->size_x, &data->door->size_y);

		// data->door->addr = mlx_get_data_addr(data->door->image,
		// 	&data->door->bitpp, &data->door->line, &data->door->endian);
//ytgjyznysq rjl
		data->collet = ft_init_image(data->collet);
		if (!data->collet)
			exit(6);
		data->collet->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
			"img/barrel.xpm", &data->collet->size_x, &data->collet->size_y);

		data->collet->addr = mlx_get_data_addr(data->collet->image,
			&data->collet->bitpp, &data->collet->line, &data->collet->endian);
	}

