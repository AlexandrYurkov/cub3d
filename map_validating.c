/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validating.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:07:59 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 16:08:01 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	max_x_y(t_map *structure, int max_x, int max_y)
{
	int	j;
	int	i;

	j = 1;
	while (j < max_y)
	{
		i = 1;
		while (i < max_x)
		{
			if (!(map_check(structure, i, j)))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

static int	line_count(char **map)
{
	int	i;

	i = 0;
	while (map[i++])
		;
	return (i - 1);
}

static void	space_fill(char **map, int max_x)
{
	char	**tmp_map;
	char	*line;
	int		i;

	tmp_map = map;
	while (*tmp_map)
	{
		if (ft_strlen(*tmp_map) < max_x)
		{
			line = *tmp_map;
			*tmp_map = malloc(sizeof(char) * max_x + 1);
			(*tmp_map)[max_x] = '\0';
			i = -1;
			while (line[++i])
				(*tmp_map)[i] = line[i];
			while (i < max_x)
			{
				(*tmp_map)[i] = ' ';
				i++;
			}
			free(line);
		}
		tmp_map++;
	}
}

static int	max_line(char **map)
{
	int		res;
	int		i;
	char	**tmp_map;
	char	*line;

	tmp_map = map;
	res = 0;
	while (*tmp_map)
	{
		i = 0;
		line = *tmp_map;
		while (*line)
		{
			i++;
			line++;
		}
		if (i > res)
			res = i;
		tmp_map++;
	}
	return (res);
}

int	map_validating(t_map *structure)
{
	int	max_x;
	int	max_y;
	int	i;

	i = -1;
	max_x = max_line(structure->map);
	max_y = line_count(structure->map);
	space_fill(structure->map, max_x);
	while (++i < max_x)
	{
		if ((structure->map[0][i] != '1' && structure->map[0][i] != ' ') \
		|| (structure->map[max_y - 1][i] != ' ' \
		&& structure->map[max_y - 1][i] != '1'))
			return (0);
	}
	i = -1;
	while (++i < max_y)
	{
		if ((structure->map[i][0] != '1' && structure->map[i][0] != ' ') \
		|| (structure->map[i][max_x - 1] != ' ' && \
		structure->map[i][max_x - 1] != '1'))
			return (0);
	}
	return (max_x_y(structure, max_x, max_y));
}
