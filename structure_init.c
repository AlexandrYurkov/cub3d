/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:08:18 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 16:08:19 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_name(int argc, char *str)
{
	int	i;
	int	fd;

	if (argc != 2)
	{
		printf("Error: Usage: ./cub3D filename.cub\n");
		return (-1);
	}
	i = ft_strlen(str);
	if (i < 4 || (str[i - 1] != 'b' || str[i - 2] != 'u' || \
		str[i - 3] != 'c' || str[i - 4] != '.'))
	{
		printf("Error: %s: Wrong map extension\n", str);
		return (-1);
	}
	else
	{
		fd = open(str, O_RDONLY);
		if (fd < 0)
			printf("Error: %s: No such file\n", str);
		return (fd);
	}
	return (fd);
}

void	structure_init(t_map *structure)
{
	structure->win_w = WIN_WIDTH;
	structure->win_h = WIN_HEIGHT;
	structure->no_path = NULL;
	structure->so_path = NULL;
	structure->we_path = NULL;
	structure->ea_path = NULL;
	structure->f_r = -1;
	structure->f_g = -1;
	structure->f_b = -1;
	structure->c_r = -1;
	structure->c_g = -1;
	structure->c_b = -1;
	structure->player_pos = malloc(sizeof(t_player));
	if (!structure->player_pos)
		structure->error = 1;
	structure->player_pos->x = -1;
	structure->player_pos->y = -1;
	structure->map_in_line = NULL;
	structure->map_start = 0;
}
