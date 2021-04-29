/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:05:30 by gupatric          #+#    #+#             */
/*   Updated: 2019/11/09 11:57:42 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	sign;

	if (n < 0)
	{
		sign = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		sign = n;
	if (sign > 9)
		ft_putnbr_fd(sign / 10, fd);
	ft_putchar_fd(sign % 10 + '0', fd);
}
