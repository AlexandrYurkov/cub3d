/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:07:39 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 16:07:41 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	game_configs_check(t_map *structure)
{
	if (structure->no_path && structure->so_path && \
		structure->we_path && structure->ea_path && structure->f_r != -1 && \
		structure->c_r != -1 && structure->map_start)
		return (1);
	printf("Error: wrong game configs\n");
	return (0);
}

int	map_proc(t_map *structure, char *line, int fd)
{
	structure->map_in_line = map_parser(line, fd);
	if (!structure->map_in_line)
	{
		printf("Error: wrong game settings\n");
		return (0);
	}
	if (!(check_map_again(fd, line)))
	{
		free(structure->map_in_line);
		return (0);
	}
	line = NULL;
	if (!(map_reader(structure, structure->map_in_line)))
	{
		printf("Error: map is not valid\n");
		return (0);
	}
	free(structure->map_in_line);
	close(fd);
	cub3d(structure);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	structure;
	int		fd;
	char	*line;

	fd = check_map_name(argc, argv[1]);
	if (fd < 0)
		return (1);
	structure_init(&structure);
	while (get_next_line(fd, &line) > 0)
	{	
		if (!(parse_game_configs(&structure, line)))
		{
			printf("Error: wrong game configs\n");
			return (1);
		}
		if (structure.map_start)
			break ;
		free(line);
	}
	if (!(game_configs_check(&structure)))
		return (1);
	if (!(map_proc(&structure, line, fd)))
		return (1);
	return (0);
}
