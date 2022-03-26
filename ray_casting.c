/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:15:20 by lfallon           #+#    #+#             */
/*   Updated: 2022/03/24 22:15:33 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	countres(double xx, double yy)
{
	if (fabs(xx) == 0)
		return (fabs(yy) + 0.000001);
	else if (fabs(yy) == 0)
		return (fabs(xx) + 0.000001);
	else if (fabs(xx) < fabs(yy))
		return (fabs(xx) + 0.000001);
	else
		return (fabs(yy) + 0.000001);
}

static double	norm_ver(double *yy, double x, double y, double a)
{
	*yy = (y - (int)y) / (sin(correct_angle(a)));
	return (((int)x - x + 1) / cos(a));
}

void	ray_casting(double *c, double x, double y, double a)
{
	double	xx;
	double	yy;
	double	result;

	if ((a > 0 && a <= M_PI_2) || (a > 0 + 2 * M_PI && a <= M_PI_2 + 2 * M_PI))
	{
		xx = (((int)x - x + 1) / cos(a));
		yy = (((int)y - y + 1) / sin(a));
	}
	else if (a > M_PI_2 && a < M_PI)
	{
		xx = (x - (int)x) / (cos(correct_angle(a)));
		yy = (((int)y - y + 1) / sin(a));
	}
	else if (a <= -M_PI_2 + 2 * M_PI && a >= M_PI)
	{
		xx = (x - (int)x) / (cos(correct_angle(a)));
		yy = (y - (int)y) / (sin(correct_angle(a)));
	}
	else
		xx = norm_ver(&yy, x, y, a);
	result = countres(xx, yy);
	*c = *c + result;
}
