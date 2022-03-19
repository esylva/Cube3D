/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:49:56 by  esylva           #+#    #+#             */
/*   Updated: 2022/03/19 16:46:49 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_separate_textures(char *str, t_data *data)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 'N' && (*(str + 1) == 'O'))
	{
		data->north = ft_save_texture(str + 2, data->north);
		if (!data->north)
			return(0);
	}
	else if (*str == 'S' && (*(str + 1) == 'O'))
	{
		data->south = ft_save_texture(str + 2, data->south);
		if (!data->south)
			return(0);
	}
	else if (*str == 'W' && (*(str + 1) == 'E'))
	{
		data->west = ft_save_texture(str + 2, data->west);
		if (!data->west)
			return(0);
	}
	else if (!ft_separate_textures_1(str, data))
		return(0);
	return (1);
}
	
	int	ft_separate_textures_1(char *str, t_data *data)
	{
	if (*str == 'E' && *(str + 1) == 'A')
	{
		data->east = ft_save_texture(str + 2, data->east);
		if (!data->east)
			return(0);
	}
	else if (*str == 'C' && *(str + 1) == ' ')
	{
		data->cloud = ft_save_texture_c(str + 2, data->cloud, data);
		if (!data->cloud)
			return(0);
	}
	else if (*str == 'F' && *(str + 1) == ' ')
	{
		data->ground = ft_save_texture_c(str + 2, data->ground, data);
		if (!data->ground)
			return(0);
	}
	return (1); //при успехе
}

t_image	*ft_save_texture(char *str, t_image *wall)
{
	char *tmp;
	int	fd;

	tmp = ft_strtrim(str, "\t\v\n\f\r ");
	wall = ft_init_image(wall);
	if (!wall)
		return (NULL);
	fd = open(tmp, O_RDONLY);
	if (fd != -1)
	{
		if (read(fd, 0, 0) != -1)
		{
			close(fd);
			wall->loc = ft_strdup(tmp);
			return (wall);
		}
		close(fd);
	}
	free(wall);
	wall = NULL;
	return (NULL);
}

t_image	*ft_save_texture_c(char *str, t_image *wall, t_data *data)
{
	if (data->bonus)
	{
		if(!ft_save_texture(str, wall))
			return(NULL);
	}
	else
	{
		wall = ft_init_image(wall);
		if (!wall)
			return (NULL);
		wall->trgb = 0;
		if (ft_parsing_trgb(str, &wall->trgb))
		{
			free(wall);
			wall = NULL;
			return(NULL);
		}
	}
	return (wall);
}

int	ft_parsing_trgb(char *str, int *trgb)
{
	int	n;
	int	i;

	i = 0;
	while (*str)
	{
		n = 0;
		str += ft_numspases(str);
		while (ft_isdigit(*str))
		{
			n = n * 10 + *str - '0';
			str++;
		}
		if (n > 255)
			return(MAP_ERROR);
		else
			*trgb = (*trgb << 8) + n;
		str += ft_numspases(str);
		if (i++ < 3 && *str == ',')
			str++;
		else if (*str)
			return(MAP_ERROR);
	}
	return (0);
}


int	ft_tind_map_begin(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '1')
			i++;
		else
			return (0);
	}
	return (i);
}
