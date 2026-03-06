/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsignednum.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:06:39 by djang             #+#    #+#             */
/*   Updated: 2024/03/17 20:06:42 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_unsigend_putnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_unsigend_putnbr_fd(n / 10, fd);
		ft_unsigend_putnbr_fd(n % 10, fd);
	}
	else
	{
		n += 48;
		write(fd, &n, 1);
	}
}

int	ft_unsigend_putnbr_fd_counter(unsigned int n)
{
	unsigned int	temp;
	int				i;

	temp = n;
	i = 1;
	while (temp >= 10)
	{
		temp = temp / 10;
		i++;
	}
	ft_unsigend_putnbr_fd(n, 1);
	return (i);
}
