/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:08:08 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 16:08:09 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_textures(char **path, char *line)
{
	if (*path)
		return (0);
	line += 2;
	if (*line != ' ')
		return (0);
	while (*line == ' ' && *line)
		line++;
	*path = ft_strdup(line, -1);
	return (1);
}

static int	check_textures_prefix(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (1);
	return (0);
}

static int	if_textures(t_map *structure, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (parse_textures(&structure->no_path, line));
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (parse_textures(&structure->ea_path, line));
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (parse_textures(&structure->so_path, line));
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (parse_textures(&structure->we_path, line));
	return (1);
}

int	parse_game_configs(t_map *structure, char *line)
{
	if (!(*line))
		return (1);
	else if (check_textures_prefix(line))
		return (if_textures(structure, line));
	else if (ft_strncmp(line, "F", 1) == 0)
		return (parse_floor(structure, line));
	else if (ft_strncmp(line, "C", 1) == 0)
		return (parse_ceil(structure, line));
	else
		structure->map_start = 1;
	return (1);
}
