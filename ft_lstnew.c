/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:56:40 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/04/29 13:23:56 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	if (!content)
		return (NULL);
	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
