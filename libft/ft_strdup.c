/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:53:57 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 15:53:59 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str, ssize_t n)
{
	char			*res;
	char			*check_mem;

	if (n == -1)
		n = ft_strlen(str);
	check_mem = malloc(sizeof(char) * (n + 1));
	if (!(check_mem))
		return (NULL);
	res = check_mem;
	while (n-- > 0)
	{
		*check_mem++ = *(char *)str++;
	}
	*check_mem = '\0';
	return (res);
}
