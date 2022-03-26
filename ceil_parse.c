/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:07:16 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 16:07:17 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color(int *get_color, char **line)
{
	*get_color = 0;
	while (ft_isdigit(**line))
	{
		*get_color = *get_color * 10 + **line - 48;
		(*line)++;
		if (*get_color > 255)
			return (0);
	}
	return (1);
}

static int	parse_ceil_2(t_map *structure, char *line, int comma)
{
	if (comma != 1 || !(ft_isdigit(*line)) || !(*line))
		return (0);
	if (!parse_color(&structure->c_g, &line))
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
	if (!parse_color(&structure->c_b, &line))
		return (0);
	while (*line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (1);
}

int	parse_ceil(t_map *structure, char *line)
{
	int		comma;

	if (structure->c_r != -1 || structure->c_g != -1 || \
		structure->c_b != -1)
		return (0);
	line++;
	if (*line != ' ')
		return (0);
	while (*line == ' ')
		line++;
	if (!(*line) || !(ft_isdigit(*line)))
		return (0);
	if (!parse_color(&structure->c_r, &line))
		return (0);
	comma = 0;
	while (*line == ' ' || *line == ',')
	{
		if (*line == ',')
			comma++;
		line++;
	}
	if (!(parse_ceil_2(structure, line, comma)))
		return (0);
	return (1);
}
