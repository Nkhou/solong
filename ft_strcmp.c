/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:27:26 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/05/12 17:32:02 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(char *s1, char s2)
{
	unsigned char	*my_s1;
	int				i;

	i = 0;
	my_s1 = (unsigned char *)s1;
	while (my_s1[i] != '\0')
	{
		if (my_s1[i] != s2)
			return (my_s1[i] - s2);
		i++;
	}
	return (0);
}
