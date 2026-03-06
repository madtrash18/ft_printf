/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:16:34 by djang             #+#    #+#             */
/*   Updated: 2024/03/17 20:16:36 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_pointer_putnbr_innerfunc(unsigned long long n, \
int fd)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= 16)
	{
		ft_pointer_putnbr_innerfunc(n / 16, fd);
		ft_pointer_putnbr_innerfunc(n % 16, fd);
	}
	else
	{
		write(fd, &hexa[n], 1);
	}
}

int	ft_pointer_putnbr_fd(unsigned long long n, int fd)
{
	unsigned long long		temp;
	int						k;

	temp = n;
	k = 1;
	if (!n)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	while (temp >= 16)
	{
		temp = temp / 16;
		k++;
	}
	write(fd, "0", 1);
	write(fd, "x", 1);
	ft_pointer_putnbr_innerfunc(n, fd);
	return (k + 2);
}
