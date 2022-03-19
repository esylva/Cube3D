/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:45:19 by esylva            #+#    #+#             */
/*   Updated: 2022/03/19 19:05:47 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_data	*ft_data_init(t_data *data)
{
	int	error;

	data = (t_data *)malloc(sizeof(t_data));
	error = errno;
	if (!data)
	{
		printf("%s\n", strerror(error));
		return(NULL);
	}
	data->window = NULL;
	data->map = NULL;
	data->player = NULL;
	data->ground = NULL;
	data->cloud = NULL;
	data->north = NULL;
	data->east = NULL;
	data->south = NULL;
	data->west = NULL;
	data->door = NULL;
	data->loot = NULL;
	data->bonus = BONUS; 
	if (ft_init_main_struct(data))
		return(NULL);
	return (data);
}

int	ft_init_main_struct(t_data *data)
// функция инициализации (и удаления при неудаче) переменных основной структуры
{
	data->window = ft_init_window(data->window);
	return (0);
}

t_image	*ft_init_image(t_image *wall)
{
	wall = (t_image *)malloc(sizeof(t_image));
	if (!wall)
		return (NULL);
	wall->loc = NULL;
	wall->image = NULL;
	wall->addr = NULL;
	wall->line = 0;
	wall->bitpp = 0;
	wall->endian = 0;
	wall->trgb = 0;
	return (wall);
}

int		ft_init_map(t_data *data, t_list *map, int weght, int hight)
{
	int 	i;
	t_list	*tmp;

	i = -1;
	tmp = map;
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
		return(MAP_ERROR);
	data->map->coords = NULL;
	data->map->exit = 0;
	data->map->loot = 0;
	data->map->x = 0;
	data->map->y = 0;
	data->map->size_x = weght;
	data->map->size_y = hight;

	data->map->coords = (char **)malloc(sizeof(char *) * (hight + 1));
	if (!data->map->coords)
		return(MAP_ERROR);
	data->map->coords[hight] = NULL;
	while(i < hight)
	{
		data->map->coords[i] = (char *)malloc(sizeof(char) * (weght + 1));
		if (!data->map->coords[i])
		{
			// data->map->coords = free_2d_arr(data->map->coords);
			return(MAP_ERROR);
		}
		i++;
	}
	i = -1;
	while (++i < hight)
	{
		ft_copy_str(data->map->coords[i], tmp->content, weght);
		tmp = tmp->next;
	}
	return (0);
}

t_window	*ft_init_window(t_window *window)
{
	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	window->img = NULL;
	window->weight = 640;
	window->height = 480;
	window->coords = NULL;
	return (window);
}
