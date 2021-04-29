/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:07:00 by gupatric          #+#    #+#             */
/*   Updated: 2019/11/06 12:08:11 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		index;
	t_list	*tmp;

	tmp = lst;
	index = 0;
	while (tmp)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}
