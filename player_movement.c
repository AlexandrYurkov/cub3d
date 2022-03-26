/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:19:54 by lfallon           #+#    #+#             */
/*   Updated: 2022/03/24 22:20:10 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	step_forward(t_data *img)
{
	if (img->struct_map->map[(int)(img->struct_map->player_pos->y + 0.2 * \
		sin(img->struct_map->player_pos->player_facing))] \
		[(int)(img->struct_map->player_pos->x + 0.2 * \
		cos(img->struct_map->player_pos->player_facing))] == '1' || \
		img->struct_map->map[(int)(img->struct_map->player_pos->y + 0.2 * \
		sin(img->struct_map->player_pos->player_facing))] \
		[(int)(img->struct_map->player_pos->x + 0.2 * \
		cos(img->struct_map->player_pos->player_facing))] == ' ' || \
		img->struct_map->map[(int)(img->struct_map->player_pos->y + 0.2 * \
		sin(img->struct_map->player_pos->player_facing))] \
		[(int)(img->struct_map->player_pos->x + 0.2 * \
		cos(img->struct_map->player_pos->player_facing))] == '\0')
		return (0);
	img->struct_map->player_pos->y += 0.2 * \
		sin(img->struct_map->player_pos->player_facing);
	img->struct_map->player_pos->x += 0.2 * \
		cos(img->struct_map->player_pos->player_facing);
	return (1);
}

int	step_backward(t_data *img)
{
	if (img->struct_map->map[(int)(img->struct_map->player_pos->y + 0.1 * \
		sin(img->struct_map->player_pos->player_facing + M_PI))] \
		[(int)(img->struct_map->player_pos->x + 0.1 * \
		cos(img->struct_map->player_pos->player_facing + M_PI))] == '1' || \
		img->struct_map->map[(int)(img->struct_map->player_pos->y + 0.1 * \
		sin(img->struct_map->player_pos->player_facing + M_PI))] \
		[(int)(img->struct_map->player_pos->x + 0.1 * \
		cos(img->struct_map->player_pos->player_facing + M_PI))] == ' ' || \
		img->struct_map->map[(int)(img->struct_map->player_pos->y + 0.1 * \
		sin(img->struct_map->player_pos->player_facing + M_PI))] \
		[(int)(img->struct_map->player_pos->x + 0.1 * \
		cos(img->struct_map->player_pos->player_facing + M_PI))] == '\0')
		return (0);
	img->struct_map->player_pos->y += 0.1 * \
		sin(img->struct_map->player_pos->player_facing + M_PI);
	img->struct_map->player_pos->x += 0.1 * \
		cos(img->struct_map->player_pos->player_facing + M_PI);
	return (1);
}

int	step_left(t_data *img)
{
	double	x;
	double	y;

	y = img->struct_map->player_pos->y + 0.1 * \
		sin(img->struct_map->player_pos->player_facing - M_PI_2);
	x = img->struct_map->player_pos->x + 0.1 * \
		cos(img->struct_map->player_pos->player_facing - M_PI_2);
	if ((img->struct_map->map[(int)y][(int)x] == '1' || \
		img->struct_map->map[(int)y][(int)x] == '\0' || \
		img->struct_map->map[(int)y][(int)x] == ' '))
		return (0);
	y = img->struct_map->player_pos->y + 0.2 * \
		sin(img->struct_map->player_pos->player_facing - M_PI_2);
	x = img->struct_map->player_pos->x + 0.2 * \
		cos(img->struct_map->player_pos->player_facing - M_PI_2);
	if ((img->struct_map->map[(int)y][(int)x] == '1' || \
		img->struct_map->map[(int)y][(int)x] == '\0' || \
		img->struct_map->map[(int)y][(int)x] == ' '))
		return (0);
	img->struct_map->player_pos->y += 0.1 * \
		sin(img->struct_map->player_pos->player_facing - M_PI_2);
	img->struct_map->player_pos->x += 0.1 * \
		cos(img->struct_map->player_pos->player_facing - M_PI_2);
	return (1);
}

int	step_right(t_data *img)
{
	double	y;
	double	x;

	y = img->struct_map->player_pos->y + 0.1 * \
		sin(img->struct_map->player_pos->player_facing + M_PI_2);
	x = img->struct_map->player_pos->x + 0.1 * \
		cos(img->struct_map->player_pos->player_facing + M_PI_2);
	if (img->struct_map->map[(int)y][(int)x] == '1' || \
		img->struct_map->map[(int)y][(int)x] == '\0' || \
		img->struct_map->map[(int)y][(int)x] == ' ')
		return (0);
	y = img->struct_map->player_pos->y + 0.2 * \
		sin(img->struct_map->player_pos->player_facing + M_PI_2);
	x = img->struct_map->player_pos->x + 0.2 * \
		cos(img->struct_map->player_pos->player_facing + M_PI_2);
	if (img->struct_map->map[(int)y][(int)x] == '1' || \
		img->struct_map->map[(int)y][(int)x] == '\0' || \
		img->struct_map->map[(int)y][(int)x] == ' ')
		return (0);
	img->struct_map->player_pos->y += 0.1 * \
		sin(img->struct_map->player_pos->player_facing + M_PI_2);
	img->struct_map->player_pos->x += 0.1 * \
		cos(img->struct_map->player_pos->player_facing + M_PI_2);
	return (1);
}
