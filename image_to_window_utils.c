/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:10:30 by lfallon           #+#    #+#             */
/*   Updated: 2022/03/24 22:10:33 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(void)
{
	exit(0);
}

double	correct_angle(double angle)
{
	if (angle >= 2 * M_PI)
		return (angle - 2 * M_PI);
	else if (angle < 0)
		return (angle + 2 * M_PI);
	return (angle);
}

void	init_all(t_data *img, void **mlx, void **mlx_win)
{
	no_img_init(*mlx, img);
	we_img_init(*mlx, img);
	so_img_init(*mlx, img);
	ea_img_init(*mlx, img);
	if (img->struct_map->error == 1)
	{
		printf("Error: invalid textures\n");
		exit(1);
	}
	*mlx_win = mlx_new_window(*mlx, \
	img->struct_map->win_w, img->struct_map->win_h, "cub3D");
	img->mlx = *mlx;
	img->mlx_win = *mlx_win;
	img->img = mlx_new_image(*mlx, img->struct_map->win_w, \
	img->struct_map->win_h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}
