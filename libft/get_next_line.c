/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:54:41 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 15:54:52 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cut_it_free_it(char **stub, long end)
{
	char	*temp;

	end++;
	temp = ft_strdup(*stub + end, -1);
	free(*stub);
	*stub = ft_strdup(temp, -1);
	free(temp);
	temp = NULL;
}

static void	free_it(char **str)
{
	free(*str);
	*str = NULL;
}

static void	free_norm(char **kostyl, char **temp)
{
	free_it(kostyl);
	free_it(temp);
}

static long	find_backslash_n(char **stub, int fd, char *n)
{
	char	*temp;
	char	*kostyl;
	ssize_t	i;

	while (!n)
	{
		temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0)
		{
			free_it(&temp);
			return (-2);
		}
		temp[i] = '\0';
		if (i == 0)
		{
			free_it(&temp);
			return (-1);
		}
		kostyl = *stub;
		*stub = ft_strjoin(*stub, temp);
		free_norm(&kostyl, &temp);
		n = ft_strchr(*stub, '\n');
	}
	return (n - *stub);
}

int	get_next_line(int fd, char **line)
{
	static char	*stub;
	long		end;

	if (fd < 0 || !line)
		return (-1);
	if (!stub)
		stub = ft_strdup("", 0);
	end = find_backslash_n(&stub, fd, ft_strchr(stub, '\n'));
	if (end == -2)
	{
		free(stub);
		stub = NULL;
		return (-1);
	}
	if (end == -1)
	{
		*line = ft_strdup(stub, -1);
		free(stub);
		stub = NULL;
		return (0);
	}
	*line = ft_strdup(stub, end);
	cut_it_free_it(&stub, end);
	return (1);
}
