/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:07:53 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 16:07:55 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_check(t_map *structure, int i, int j)
{
	if (structure->map[j][i] == '0' && (structure->map[j - 1][i] == ' ' || \
		structure->map[j][i - 1] == ' ' || \
		structure->map[j + 1][i] == ' ' || \
		structure->map[j][i + 1] == '\0' || \
		structure->map[j][i + 1] == ' '))
		return (0);
	else if (structure->map[j][i] != '0' && structure->map[j][i] != '1' && \
		structure->map[j][i] != ' ')
	{
		printf("Error: unknown symbol in a map: %c\n", structure->map[j][i]);
		return (0);
	}
	return (1);
}

static void	set_player_facing(t_map *structure, char c)
{
	if (c == 'N')
		structure->player_pos->player_facing = M_PI_2 * 3;
	if (c == 'E')
		structure->player_pos->player_facing = 0;
	if (c == 'S')
		structure->player_pos->player_facing = M_PI_2;
	if (c == 'W')
		structure->player_pos->player_facing = M_PI;
}

static int	is_player_pos(t_map *structure, char **map_tab, int *x, int *y)
{
	while (**map_tab)
	{
		if (**map_tab == 'N' || **map_tab == 'E' || \
		**map_tab == 'W' || **map_tab == 'S')
		{
			if (structure->player_pos->x != -1)
				return (0);
			set_player_facing(structure, **map_tab);
			structure->player_pos->x = (double)(*x) + 0.5;
			structure->player_pos->y = (double)(*y) + 0.5;
			**map_tab = '0';
		}
		(*x)++;
		(*map_tab)++;
	}
	return (1);
}

int	avoid_norme(t_map *structure)
{
	if (structure->player_pos->x == -1)
	{
		printf("Error: player is not set\n");
		return (0);
	}
	if (!(map_validating(structure)))
		return (0);
	else
		return (1);
}

int	map_reader(t_map *structure, char *map_in_line)
{
	int		x;
	int		y;
	int		i;
	char	*tmp;

	i = 0;
	x = 0;
	y = 0;
	structure->map = ft_split(map_in_line, '\n');
	while (structure->map[i])
	{
		tmp = structure->map[i];
		if (!(is_player_pos(structure, &tmp, &x, &y)))
			return (0);
		y++;
		i++;
		x = 0;
	}
	if (!(avoid_norme(structure)))
		return (0);
	return (1);
}
