/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:39:04 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/21 18:27:20 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_point(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
			return (i);
		i++;
	}
	ft_error("Error input\n");
	return (i);
}

int	ft_strrchr(char *s, char *c)
{
	int		i;
	int		j;

	i = find_point(s);
	j = find_point(c);
	while (s[i] && c[j])
	{
		if (s[i] != c[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
