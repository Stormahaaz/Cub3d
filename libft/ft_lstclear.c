/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:34:14 by gupatric          #+#    #+#             */
/*   Updated: 2019/11/09 13:13:48 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *lst;
	while (ptr)
	{
		temp = ptr;
		ft_lstdelone(ptr, del);
		ptr = temp->next;
	}
	*lst = NULL;
}
