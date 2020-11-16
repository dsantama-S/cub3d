/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 09:14:13 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/14 10:07:03 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
	else if (n <= 9 && n >= 0)
		ft_putchar_fd(n + 48, fd);
	else if (n >= -9 && n <= 0)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd((n * -1) + 48, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(((n % 10) * -1) + 48, fd);
	}
}
