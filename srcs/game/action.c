/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:42:45 by esylva            #+#    #+#             */
/*   Updated: 2022/05/14 16:35:03 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	mouse_move(int x, int y, t_data *data)
{
	static int	mouse_x = W_PANEL / 2;
	static int	mouse_y = H_PANEL / 2;

	if (x > 0 && x < W_PANEL && y > 0 && y < H_PANEL)
	{
		mlx_mouse_hide(data->window->mlx_ptr, data->window->win_ptr);
		data->player->look -= ((double)(PI / 2) / (W_PANEL / 2)
				* (mouse_x - x));
		ft_paint(data);
	}
	else
		mlx_mouse_show();
	if (y > H_PANEL / 4 && y < H_PANEL / 4 * 3)
		mlx_mouse_move(data->window->win_ptr, mouse_x, mouse_y);
	return (0);
}

void	ft_turn_right(t_data *data)
{
	data->player->look += PI / 60;
	if (data->player->look > 2 * PI)
	{
		data->player->look -= 2 * PI;
	}
	ft_paint(data);
}

void	ft_turn_left(t_data *data)
{
	data->player->look -= PI / 60;
	if (data->player->look < 0)
	{
		data->player->look += 2 * PI;
	}
	ft_paint(data);
}

t_player	*ft_init_player(t_player *player)
{
	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->look = -1;
	player->pos_x = 0;
	player->pos_y = 0;
	return (player);
}

t_wall	*ft_init_wall(t_wall *wall)
{
	wall = (t_wall *)malloc(sizeof(t_wall));
	if (!wall)
		return (NULL);
	wall->f_door = 0;
	wall->wall = 0;
	wall->tmp = 0;
	wall->kx = 0;
	wall->ky = 0;
	wall->dx = 0;
	wall->dy = 0;
	return (wall);
}
