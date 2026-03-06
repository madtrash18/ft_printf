/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_intnum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:06:18 by djang             #+#    #+#             */
/*   Updated: 2024/03/17 20:06:20 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0 && n > -2147483648)
	{
		n = n * -1;
		write(fd, "-", 1);
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		n += 48;
		write(fd, &n, 1);
	}
}

int	ft_putnbr_fd_counter(int n)
{
	int	temp;
	int	i;

	temp = n;
	i = 0;
	if (temp <= 0)
		i++;
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	return (i);
}
