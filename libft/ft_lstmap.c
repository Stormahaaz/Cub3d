/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:27:25 by gupatric          #+#    #+#             */
/*   Updated: 2019/11/09 12:02:53 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;

	if (lst && (new = malloc(sizeof(t_list))))
	{
		if (!(new->content = f(lst->content)))
		{
			ft_lstdelone(new, del);
			return (NULL);
		}
		new->next = ft_lstmap(lst->next, f, del);
		return (new);
	}
	return (NULL);
}
