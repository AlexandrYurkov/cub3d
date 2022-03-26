/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graffiti_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:43:43 by lfallon           #+#    #+#             */
/*   Updated: 2022/03/24 22:43:45 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 7));
	*(unsigned int *)dst = color;
}

int	get_color(t_xpm *img, int x, int y)
{
	char	*dst;
	int		color;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(int *)dst;
	return (color);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
