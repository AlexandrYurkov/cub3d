/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:45:02 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 16:45:04 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <string.h>

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

typedef struct s_player
{
	double			x;
	double			y;
	double			xx;
	double			yy;
	double			player_facing;
}					t_player;

typedef struct s_xpm
{
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				w;
	int				h;
	void			*img;
	char			name;
}					t_xpm;

typedef struct s_map
{
	long			win_w;
	long			win_h;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c_r;
	int				c_g;
	int				c_b;
	char			*map_in_line;
	t_player		*player_pos;
	char			**map;
	int				error;
	int				map_start;
}					t_map;

typedef struct s_data
{
	void			*img;
	t_xpm			*no_img;
	t_xpm			*so_img;
	t_xpm			*we_img;
	t_xpm			*ea_img;
	double			*wall_d;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*mlx_win;
	t_map			*struct_map;
}					t_data;

int		check_map_name(int argc, char *str);
void	structure_init(t_map *struct_map);
char	*map_parser(char *line, int fd);
int		map_reader(t_map *struct_map, char *map);
void	cub3d(t_map *struct_map);
int		create_trgb(int t, int r, int g, int b);
double	correct_angle(double angle);
void	ray_casting(double *c, double x, \
		double y, double angle);
int		parse_game_configs(t_map *struct_map, char *line);
int		parse_ceil(t_map *struct_map, char *line);
int		parse_floor(t_map *struct_map, char *line);
int		parse_color(int *get_color, char **line);
int		check_map_again(int fd, char *line);
void	no_img_init(void *mlx, t_data *img);
void	so_img_init(void *mlx, t_data *img);
void	we_img_init(void *mlx, t_data *img);
void	ea_img_init(void *mlx, t_data *img);
int		map_validating(t_map *struct_map);
int		map_check(t_map *struct_map, int i, int j);
void	init_all(t_data *img, void **mlx, void **mlx_win);
int		step_forward(t_data *img);
int		step_backward(t_data *img);
int		step_left(t_data *img);
int		step_right(t_data *img);
void	graffiti(t_data *img, int j, double c, double angle);
int		get_color(t_xpm *img, int x, int y);
void	pixel_put(t_data *img, int x, int y, int color);
void	print_img_3d(t_map *struct_map, t_data *img);
int		ft_close(void);

#endif
