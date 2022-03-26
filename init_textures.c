/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:24:44 by lfallon           #+#    #+#             */
/*   Updated: 2022/03/24 22:24:47 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	no_img_init(void *mlx, t_data *img)
{
	img->no_img = malloc(sizeof(t_xpm));
	img->no_img->img = mlx_xpm_file_to_image(mlx, img->struct_map->no_path, \
	&img->no_img->w, &img->no_img->h);
	if (!img->no_img->img)
	{
		img->struct_map->error = 1;
		return ;
	}
	img->no_img->name = 'n';
	img->no_img->addr = mlx_get_data_addr(img->no_img->img, \
	&img->no_img->bits_per_pixel, &img->no_img->line_length, \
	&img->no_img->endian);
}

void	so_img_init(void *mlx, t_data *img)
{
	img->so_img = malloc(sizeof(t_xpm));
	img->so_img->img = mlx_xpm_file_to_image(mlx, img->struct_map->so_path, \
	&img->so_img->w, &img->so_img->h);
	if (!img->so_img->img)
	{
		img->struct_map->error = 1;
		return ;
	}
	img->so_img->name = 's';
	img->so_img->addr = mlx_get_data_addr(img->so_img->img, \
	&img->so_img->bits_per_pixel, &img->so_img->line_length, \
	&img->so_img->endian);
}

void	we_img_init(void *mlx, t_data *img)
{
	img->we_img = malloc(sizeof(t_xpm));
	img->we_img->img = mlx_xpm_file_to_image(mlx, img->struct_map->we_path, \
	&img->we_img->w, &img->we_img->h);
	if (!img->we_img->img)
	{
		img->struct_map->error = 1;
		return ;
	}
	img->we_img->name = 'w';
	img->we_img->addr = mlx_get_data_addr(img->we_img->img, \
	&img->we_img->bits_per_pixel, &img->we_img->line_length, \
	&img->we_img->endian);
}

void	ea_img_init(void *mlx, t_data *img)
{
	img->ea_img = malloc(sizeof(t_xpm));
	img->ea_img->img = mlx_xpm_file_to_image(mlx, img->struct_map->ea_path, \
	&img->ea_img->w, &img->ea_img->h);
	if (!img->ea_img->img)
	{
		img->struct_map->error = 1;
		return ;
	}
	img->ea_img->addr = mlx_get_data_addr(img->ea_img->img, \
	&img->ea_img->bits_per_pixel, &img->ea_img->line_length, \
	&img->ea_img->endian);
	img->ea_img->name = 'e';
}
