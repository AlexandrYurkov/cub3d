/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:07:25 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 16:07:27 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_floor_2(t_map *structure, char *line, int comma)
{
	if (comma != 1 || !(ft_isdigit(*line)) || !(*line))
		return (0);
	if (!parse_color(&structure->f_g, &line))
		return (0);
	comma = 0;
	while (*line == ' ' || *line == ',')
	{
		if (*line == ',')
			comma++;
		line++;
	}
	if (comma != 1 || !(ft_isdigit(*line)) || !(*line))
		return (0);
	if (!parse_color(&structure->f_b, &line))
		return (0);
	while (*line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (1);
}

int	parse_floor(t_map *structure, char *line)
{
	int		comma;

	if (structure->f_r != -1 || structure->f_g != -1 || \
		structure->f_b != -1)
		return (0);
	line++;
	if (*line != ' ')
		return (0);
	while (*line == ' ')
		line++;
	if (!(*line) || !(ft_isdigit(*line)))
		return (0);
	if (!parse_color(&structure->f_r, &line))
		return (0);
	comma = 0;
	while (*line == ' ' || *line == ',')
	{
		if (*line == ',')
			comma++;
		line++;
	}
	if (!(parse_floor_2(structure, line, comma)))
		return (0);
	return (1);
}
