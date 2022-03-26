/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:07:47 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 16:07:48 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_again(int fd, char *line)
{
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) != 0)
		{
			printf("Error: map is not valid\n");
			free(line);
			return (0);
		}
		else
			free(line);
	}
	if (ft_strlen(line) != 0)
	{
		printf("Error: map is not valid\n");
		free(line);
		return (0);
	}
	else
		free(line);
	return (1);
}

static void	free_func(char *s1, char *s2)
{
	free(s1);
	free(s2);
	s1 = NULL;
	s2 = NULL;
}

static int	check_new_line(char *line)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (0);
	}
	return (1);
}

char	*map_parser(char *line, int fd)
{
	char	*map;
	char	*tmp;

	if (!line)
		return (NULL);
	map = ft_strdup(line, -1);
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(check_new_line(line)))
			return (map);
		tmp = map;
		map = ft_strjoin(map, "\n");
		free(tmp);
		tmp = map;
		map = ft_strjoin(map, line);
		free_func(tmp, line);
	}
	tmp = map;
	map = ft_strjoin(map, "\n");
	free(tmp);
	tmp = map;
	map = ft_strjoin(map, line);
	free_func(tmp, line);
	return (map);
}
