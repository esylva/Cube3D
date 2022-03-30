/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:46:58 by esylva            #+#    #+#             */
/*   Updated: 2022/03/30 10:17:26 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include "../libft/libft.h"

# include <math.h>

# define BONUS 1
# define NO_BONUS_STR "0NSWE"
# define BONUS_STR "0NSWEDLX"
# define ARGUMENT_OPEN_ERROR 1
# define INIT_ERROR 2
# define MAP_ERROR -10

/* keycodes for ubuntu */
# define TURN_LEFT 65361
# define TURN_RIGHT 65363
# define GO_FORWARD 119
# define GO_BACKWARD 115
# define STR_LEFT 97
# define STR_RIGHT 100
# define EXIT 65307
# define USE 101

/* keycodes for Mac */

// # define TURN_LEFT 123
// # define TURN_RIGHT 124
// # define GO_FORWARD 13
// # define GO_BACKWARD 1
// # define STR_LEFT 0
// # define STR_RIGHT 2
// # define EXIT 53
// # define USE 14

# define PI 3.14159265
# define ONE_SIZE 40
# define WOLL 0x0553300
# define UGOL PI/2
# define W_PANEL 1280
# define H_PANEL 720
# define W_MAP 200
# define M_GROUND 65355
# define SCALE 4

typedef struct s_image
{
	void	*image;
	void	*addr;
	int		line;
	int		bitpp;
	int		endian;
	char	*loc;
	int		trgb;
	int		size_x;
	int		size_y;
}				t_image;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		ray_x;
	double		ray_y;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	int			look;
	double		time;
	double		oldTime;

	double		cameraX;
	double		cameraY;
	double		rayDirX;
	double		rayDirY;

	int nScreenWidth;
	int nScreenHeight;


	float fPlayerX;
	float fPlayerY;
	float fPlayerA ;


	int nMapHeight ;
	int nMapWidth ;

	float fFOV;
	float	fDepth;
}				t_player;

// typedef struct s_camera
// {



// }				t_camera;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		**coord;
}				t_window;

typedef struct s_map
{
	int		loot;
	int		exit;
	int		x;
	int		y;
	int		size_x;
	int		size_y;
	char	**coord;
}				t_map;

typedef struct s_strite
{
	int			*i;
	t_image		*sprites;
	int			status;
}				t_sprite;


typedef struct s_data
{
	// t_camera		*camera;
	t_window		*window;
	t_map			*map;
	t_player		*player;
	t_image			*mmap;
	t_image			*ground;
	t_image			*cloud;
	t_image			*north;
	t_image			*east;
	t_image			*south;
	t_image			*west;
	t_sprite		*door;
	t_sprite		*loot;
	char			bonus;
}				t_data;
	
/* main.c */
int			ft_cube(char *carta, t_data *data);
int			ft_exit(t_data *data, int keycode);
void		ft_free_all(t_data *data);

void		ft_game(t_data *data);

/* checker.c */
int			ft_name_check(char *carta);
int			ft_check_map(t_data *data, t_list *map, int weght, int hight);
int			ft_check_inside(t_data *data, int weght, int hight, char *str);
int			ft_check_sym(int i, int j, t_data *data);
void		ft_set_look(t_data *data, int i, int j);

/* init.c */
t_data		*ft_data_init(t_data *data);
int			ft_init_main_struct(t_data *data);
t_window	*ft_init_window(t_window *window);
t_player	*ft_init_player(t_player *player);

t_image		*ft_init_image(t_image *wall);
int			ft_init_map(t_data *data, int hight, int weght);


/* parcer.c */
t_list		*ft_lstnew_m(char *content);
int			ft_parce_data(t_data *data, int fd);
int			ft_config(t_list **cub, t_data *data);
int			ft_parse_map(t_list *tmp, t_data *data);

/* parcer_utils.c */
int			ft_separate_textures(char *str, t_data *data);
int			ft_separate_textures_1(char *str, t_data *data);
t_image		*ft_save_texture(char *str, t_image *wall);
t_image		*ft_save_texture_c(char *str, t_image *wall, t_data *data);
int			ft_parsing_trgb(char *str, int *trgb);


/* parcer_utils2.c */
int			ft_empty_line(char *str);
void		ft_copy_str(char *dest, char *src, int lim);
int			ft_init_coord(t_data *data, t_list *map, int weght, int hight);
int			ft_check_rect_str(char *str);
int			ft_check_rect_col(char **str, int w, int h);


/* window.c */
int			ft_win_init(t_data *data);
void 		ft_coord(t_data *data);
void		ft_cast_rays(t_data *data, int color);
int			key_kb_hook(int keycode, t_data *data);


void		ft_img_init(t_data *data);
void		ft_img_bonus_init(t_data *data);
int			mouse_move(int keycode, t_data *data);
void		ft_draw_2D_wall(t_data *data);

/* paint_back.c */
void		ft_back_bonus(t_data *data);
void		ft_back(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_put_minimap(t_data *data);
void		ft_draw_2D_obj(t_data *data, int x, int y, int size, int color);

/* free.c */
t_window	*ft_free_window(t_window *window);
t_map		*ft_free_map(t_map *map);
t_player	*ft_free_player(t_player *player);
t_image		*ft_free_image(t_image *image);
t_sprite	*ft_free_sprite(t_sprite *sprite);

/* action.c */
void		ft_change_ground(t_data *data);

/* ft_wasd1.c */
void		ft_go_forward(t_data *data);
void		ft_str_left(t_data *data);
void		ft_go_backward(t_data *data);
void		ft_str_right(t_data *data);
void		ft_turn_right(t_data *data);
void		ft_turn_left(t_data *sdata);

/*other*/

// void		ft_Pup(t_data *data);
// void		ft_Pright(t_data *data);
// void		ft_Pdown(t_data *data);
// void		ft_Pleft(t_data *data);
// void		ft_Pclock(t_data *data);
// void		ft_Pconterclock(t_data *data);
void		ft_open_door(t_data *data);

void		ft_draw_(t_data *data, double x, double y, int color);

void		ft_draw_player(t_data *data, int color);
void		ft_paint(t_data *data);


// int		key_hook(int keycode, t_map *map);
// int		ft_player_action(t_map *map);
// void	ft_render_1(t_map *map);
// int		render_next_frame(t_map *map);

// void	ft_put_img_to_win(t_map *map);
// void	ft_img_init(t_map *map);
// int		ft_win_init(t_map *map);
// void	ft_put_by_sym(t_map *map);
// void	ft_save_player_position(t_map *map);
// void	ft_check_player_position(t_map *map);
// void	ft_check_sym(int x, int y, t_map *map);
// void	ft_check_lines(t_map *map);
// void	ft_make_map(t_map *map, int fd);
// void	ft_make_coord(t_map *map);

// void	ft_check_rect(int sh, int ne, char *line);

// t_map	*ft_map_init(t_map *map);

// void	ft_name_check(char *carta);
// void	ft_free_all(t_map *map);
#endif
