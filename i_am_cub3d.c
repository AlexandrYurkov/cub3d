/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <lfallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:49:14 by esnowbal          #+#    #+#             */
/*   Updated: 2022/03/22 22:11:45 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double				correctangle(double angle)
{
	if (angle >= 2 * M_PI)
		return (angle - 2 * M_PI);
	else if (angle < 0)
		return (angle + 2 * M_PI);
	return (angle);
}

static void			any_key_helper(t_data *img)
{
	print_3d(img->structure, img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
}

static int			any_key_2(int keycode, t_data *img)
{
	if (keycode == 2)
	{
		if (!(step_right(img)))
			return (0);
		any_key_helper(img);
	}
	else if (keycode == 124)
	{
		img->structure->player_pos->player_facing = \
		correctangle(img->structure->player_pos->player_facing + 0.1);
		any_key_helper(img);
	}
	else if (keycode == 123)
	{
		img->structure->player_pos->player_facing = \
		correctangle(img->structure->player_pos->player_facing - 0.1);
		any_key_helper(img);
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		// free(img->sprites);
		exit(0);
	}
	return (0);
}

static int			any_key(int keycode, t_data *img)
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

void				i_am_cub3d(t_map *structure)
{
	t_data		img;
	void		*mlx;
	void		*mlx_win;

	mlx = mlx_init();//поменять на дефайн разрешение экрана
	img.structure = structure;
	check_resolution(&img);//убрать
	init_all(&img, &mlx, &mlx_win);
	// if (!(img.sprites = malloc(sizeof(t_sprite) * img.structure->sprite_num)))
	// 	printf("No memory for sprites\n");
	print_3d(structure, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 17, 1L << 0, ft_close, &img);
	mlx_hook(mlx_win, 2, 1L << 0, any_key, &img);
	// mlx_hook(mlx_win, 2, 1L << 0, any_key, &img);
	mlx_loop(mlx);
}
