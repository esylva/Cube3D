/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:45:05 by esylva            #+#    #+#             */
/*   Updated: 2022/03/27 18:54:46 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	int		i;
	int		ret;
	t_data	*data;

	data = NULL;
	if (argc == 1)
	{
		printf("%s\n",
			"Please, use cub3D with arguments 'map' in format *.cub");
		return (1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			ret = ft_cube(argv[i], data);
				//  data->window->win_ptr = mlx_new_window(data->window->mlx_ptr, data->player->nScreenWidth, data->player->nScreenHeight, "THE GAME!");

// printf("%s\n ret = %d\n", argv[i], ret);
			if(ret)
				return (ret);
			i++;
		}
	}
	return (0);
}

// void	ft_game(t_data *data)
// {
// 	int x;
// 	int	y;
// 	x = 0;
// 	y = 0;
// 	// while(1)
// 	{
// 		for(int x = 0; x < data->window->weight; x+=100)
// 		{
// 			printf("w = %d\n", data->window->weight);
// 	// 		// вычисляем положение и направление
// 			data->player->cameraX = 2*x/(double)(data->window->weight)-1;			//координата x в пространстве камеры
// 			data->player->rayDirX = data->player->dirX + data->player->planeX*data->player->cameraX;
// 			data->player->rayDirY = data->player->dirY + data->player->planeY*data->player->cameraX;
// 	// 		// в какой ячейке карты мы находимся
// 			int mapX = (int)(data->player->pos_x);
// 			int mapY = (int)(data->player->pos_y);
// 	// 		//length of ray from current position to next x or y-side
// 	// 		double sideDistX;
// 	// 		double sideDistY;
// 	// 		//length of ray from one x or y-side to next x or y-side
// 	// 		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
// 	// 		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
// 	// 		double perpWallDist;
// 	// 		//what direction to step in x or y-direction (either +1 or -1)
// 	// 		int stepX;
// 	// 		int stepY;
// 	// 		int hit = 0; //was there a wall hit?
// 	// 		int side; //was a NS or a EW wall hit?
// 	// 		//calculate step and initial sideDist
// 	// 		if (rayDirX < 0)
// 	// 		{
// 	// 			stepX = -1;
// 	// 			sideDistX = (pos_x - mapX) * deltaDistX;
// 	// 		}
// 	// 		else
// 	// 		{
// 	// 			stepX = 1;
// 	// 			sideDistX = (mapX + 1.0 - pos_x) * deltaDistX;
// 	// 		}
// 	// 		if (rayDirY < 0)
// 	// 		{
// 	// 			stepY = -1;
// 	// 			sideDistY = (pos_y - mapY) * deltaDistY;
// 	// 		}
// 	// 		else
// 		// 	{
// 		// 		stepY = 1;
// 		// 		sideDistY = (mapY + 1.0 - pos_y) * deltaDistY;
// 		// 	}
// 	// 	//perform DDA
// 	// 		while (hit == 0)
// 	// 		{
// 	// 			//jump to next map square, either in x-direction, or in y-direction
// 	// 			if (sideDistX < sideDistY)
// 	// 			{
// 	// 			sideDistX += deltaDistX;
// 	// 			mapX += stepX;
// 	// 			side = 0;
// 	// 			}
// 	// 			else
// 	// 			{
// 	// 			sideDistY += deltaDistY;
// 	// 			mapY += stepY;
// 	// 			side = 1;
// 	// 			}
// 	// 			//Check if ray has hit a wall
// 	// 			if (worldMap[mapX][mapY] > 0) hit = 1;
// 	// 		}
// 	// 		//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
// 	// 		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
// 	// 		else          perpWallDist = (sideDistY - deltaDistY);
// 	// 		//Calculate height of line to draw on screen
// 	// 		int lineHeight = (int)(h / perpWallDist);
// 	// 		//calculate lowest and highest pixel to fill in current stripe
// 	// 		int drawStart = -lineHeight / 2 + h / 2;
// 	// 		if(drawStart < 0) drawStart = 0;
// 	// 		int drawEnd = lineHeight / 2 + h / 2;
// 	// 		if(drawEnd >= h) drawEnd = h - 1;
// 	// 		//texturing calculations
// 	// 		int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!
// 	// 		//calculate value of wallX
// 	// 		double wallX; //where exactly the wall was hit
// 	// 		if (side == 0) wallX = pos_y + perpWallDist * rayDirY;
// 	// 		else           wallX = pos_x + perpWallDist * rayDirX;
// 	// 		wallX -= floor((wallX));
// 	// 		//x coordinate on the texture
// 	// 		int texX = int(wallX * double(texWidth));
// 	// 		if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
// 	// 		if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;
// 	// 		// How much to increase the texture coordinate per screen pixel
// 	// 		double step = 1.0 * texHeight / lineHeight;
// 	// 		// Starting texture coordinate
// 	// 		double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
// 	// 		for(int y = drawStart; y<drawEnd; y++)
// 	// 	{
// 	// 		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
// 	// 		int texY = (int)texPos & (texHeight - 1);
// 	// 		texPos += step;
// 	// 		Uint32 color = texture[texNum][texHeight * texY + texX];
// 	// 		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
// 	// 		if(side == 1) color = (color >> 1) & 8355711;
// 	// 		buffer[y][x] = color;
// 	// 	}
// 		}
// 	}
// 	// printf("pos_x = %f\n", data->player->pos_x);
// }

 void	ft_game(t_player *player, t_data *data)
 {
	 	//  data->window->win_ptr = mlx_new_window(data->window->mlx_ptr,player->nScreenWidth, player->nScreenHeight, "THE GAME!");

	(void)data;
	(void)player;
	 while (1) // Игровой цикл
	{

		break;

	}

	// return 0;
 }

int	ft_cube(char *carta, t_data *data)
{
	int	fd;
// int i;
	fd = ft_name_check(carta);
	if (!fd)
		return (ARGUMENT_OPEN_ERROR);
	data = ft_data_init(data);
	if (!data)
		return (INIT_ERROR);
	if (ft_parce_data(data, fd))
		ft_exit (data, MAP_ERROR);
	// {
	// 	if (ft_exit (data, MAP_ERROR))
	// 		return (3);
	// }
	// data->player->pos_x = 80;					//vremenno
	// data->player->pos_y = 100;					//vremenno
		
// printf("%s\n", data->north->loc);
// printf("%s\n", data->east->loc);
// printf("%s\n", data->south->loc);
// printf("%s\n", data->west->loc);
// printf("%d\n", data->cloud->trgb);
// printf("%d\n", data->ground->trgb);
// i = -1;
// while (data->map->coord[++i])
// printf("2%s2\n", data->map->coord[i]);


	ft_win_init(data);
	// ft_game(data->player, data);
	ft_free_all(data);
	close (fd);
	return (0);
}

void	ft_free_all(t_data *data)
{
	if (data->window)
		data->window = ft_free_window(data->window);
	if (data->map)
		data->map = ft_free_map(data->map);
	if (data->player)
		data->player = ft_free_player(data->player);
	if (data->ground)
		data->ground = ft_free_image(data->ground);
	if (data->cloud) 
		data->cloud = ft_free_image(data->cloud);
	if (data->north)
		data->north = ft_free_image(data->north);
	if (data->east)
		data->east = ft_free_image(data->east);
	if (data->south)
		data->south = ft_free_image(data->south);
	if (data->west)
		data->west = ft_free_image(data->west);
	if (data->door)
		data->door = ft_free_sprite(data->door);
	if (data->loot)
		data->loot = ft_free_sprite(data->loot);
	free (data);
	data = NULL;
}

int	ft_exit(t_data *data, int keycode)
{
	ft_free_all(data);
	if (keycode == ARGUMENT_OPEN_ERROR)
		printf("Can't open the map file\n");
	if (keycode == INIT_ERROR)
		printf("Initialisation error. Not enough memory\n");
	if (keycode == MAP_ERROR)
	{
		printf("Map is invalid\n");
		keycode = 3;
	}
	// return (keycode);
	exit (keycode);
}