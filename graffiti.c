/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graffiti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:02:37 by lfallon           #+#    #+#             */
/*   Updated: 2022/03/24 22:02:51 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	find_height(t_player *player, char name)
{
	if (name == 'e')
		return (player->yy - (int)player->yy);
	else if (name == 'w')
		return ((int)player->yy + 1 - player->yy);
	else if (name == 'n')
		return (player->xx - (int)player->xx);
	else
		return ((int)player->xx + 1 - player->xx);
}

double	find_width(double wall_h, int h, int i)
{
	if (wall_h > h)
		return ((wall_h / 2 - h / 2 + i) / wall_h);
	else
		return ((i - (h / 2 - wall_h / 2)) / wall_h);
}

t_xpm	*what_wall(t_data *img)
{
	if ((int)(img->struct_map->player_pos->xx - 0.00001) != \
	(int)(img->struct_map->player_pos->xx))
		return (img->ea_img);
	else if ((int)(img->struct_map->player_pos->xx + 0.00001) != \
	(int)(img->struct_map->player_pos->xx))
		return (img->we_img);
	else if ((int)(img->struct_map->player_pos->yy - 0.00001) != \
	(int)(img->struct_map->player_pos->yy))
		return (img->so_img);
	else
		return (img->no_img);
}

void	graffiti_2(t_data *img, double wall_height, int j)
{
	t_xpm	*current_wall;
	int		i;
	int		pixel;
	int		end;

	i = -1;
	end = img->struct_map->win_h / 2 + wall_height / 2;
	if (end > img->struct_map->win_h)
		end = img->struct_map->win_h;
	pixel = img->struct_map->win_h / 2 - wall_height / 2;
	current_wall = what_wall(img);
	while (++i < img->struct_map->win_h)
	{
		if (i > pixel && i <= end)
			pixel_put(img, j, i, get_color(current_wall, \
			find_height(img->struct_map->player_pos, current_wall->name) * \
			current_wall->w, current_wall->h * find_width(wall_height, \
			img->struct_map->win_h, i)));
		else if (i <= pixel)
			pixel_put(img, j, i, create_trgb(0, img->struct_map->c_r, \
			img->struct_map->c_g, img->struct_map->c_b));
		else
			pixel_put(img, j, i, create_trgb(0, img->struct_map->f_r, \
			img->struct_map->f_g, img->struct_map->f_b));
	}
}

void	graffiti(t_data *img, int j, double c, double angle)
{
	double	wall_height;

	wall_height = img->struct_map->win_h / \
	(c * cos(img->struct_map->player_pos->player_facing - angle));
	graffiti_2(img, wall_height, j);
}
