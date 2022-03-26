/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:39:55 by lfallon           #+#    #+#             */
/*   Updated: 2022/03/24 21:40:20 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	any_key_helper(t_data *img)
{
	print_img_3d(img->struct_map, img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
}

static int	any_key_2(int keycode, t_data *img)
{
	if (keycode == 2)
	{
		if (!(step_right(img)))
			return (0);
		any_key_helper(img);
	}
	else if (keycode == 124)
	{
		img->struct_map->player_pos->player_facing = \
		correct_angle(img->struct_map->player_pos->player_facing + 0.1);
		any_key_helper(img);
	}
	else if (keycode == 123)
	{
		img->struct_map->player_pos->player_facing = \
		correct_angle(img->struct_map->player_pos->player_facing - 0.1);
		any_key_helper(img);
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	return (0);
}

static int	any_key(int keycode, t_data *img)
{
	if (keycode == 13 || keycode == 126)
	{
		if (!(step_forward(img)))
			return (0);
		any_key_helper(img);
	}
	else if (keycode == 1 || keycode == 125)
	{
		if (!(step_backward(img)))
			return (0);
		any_key_helper(img);
	}
	else if (keycode == 0)
	{
		if (!(step_left(img)))
			return (0);
		any_key_helper(img);
	}
	else
		any_key_2(keycode, img);
	return (0);
}

void	cub3d(t_map *struct_map)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	img.struct_map = struct_map;
	init_all(&img, &mlx, &mlx_win);
	print_img_3d(struct_map, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 17, 1L << 0, ft_close, &img);
	mlx_hook(mlx_win, 2, 1L << 0, any_key, &img);
	mlx_loop(mlx);
}
