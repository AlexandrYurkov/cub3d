/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:59:35 by lfallon           #+#    #+#             */
/*   Updated: 2022/03/24 21:59:40 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_finder(t_data *img, double c, double angle, int j)
{
	double	xx;
	double	yy;

	img->struct_map->player_pos->xx = \
	img->struct_map->player_pos->x + c * cos(angle);
	img->struct_map->player_pos->yy = \
	img->struct_map->player_pos->y + c * sin(angle);
	xx = img->struct_map->player_pos->xx;
	yy = img->struct_map->player_pos->yy;
	if (img->struct_map->map[(int)yy][(int)xx] == '1' \
		|| img->struct_map->map[(int)yy][(int)xx] == '\0' \
		|| img->struct_map->map[(int)yy][(int)xx] == ' ')
	{
		img->wall_d[img->struct_map->win_w - j] = c;
		return (1);
	}
	return (0);
}

void	print_img_3d(t_map *struct_map, t_data *img)
{
	int		j;
	double	c;
	double	angle;

	angle = struct_map->player_pos->player_facing - M_PI_2 / 3;
	j = 0;
	img->wall_d = malloc(sizeof(double) * img->struct_map->win_w);
	while (++j < struct_map->win_w)
	{
		angle = angle + (M_PI / 3) / struct_map->win_w;
		angle = correct_angle(angle);
		c = 0.000001;
		while (!(wall_finder(img, c, angle, j)))
			ray_casting(&c, struct_map->player_pos->xx, \
			struct_map->player_pos->yy, angle);
		graffiti(img, j - 1, c, angle);
	}
	graffiti(img, struct_map->win_w - 1, c, angle);
	free(img->wall_d);
}
