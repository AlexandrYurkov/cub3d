/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:54:19 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/26 15:54:23 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strlen(const char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
