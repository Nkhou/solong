/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:18:33 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/23 14:48:04 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strnline( char *s)
{
	int	i;

	i = 0;
    if (!s)
        return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}