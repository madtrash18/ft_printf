/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexalowernum.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:12:27 by djang             #+#    #+#             */
/*   Updated: 2024/03/17 20:12:29 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_hexa_putnbr_innerfunc(unsigned int n, int fd)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= 16)
	{
		ft_hexa_putnbr_innerfunc(n / 16, fd);
		ft_hexa_putnbr_innerfunc(n % 16, fd);
	}
	else
	{
		write(fd, &hexa[n], 1);
	}
}

int	ft_hexa_putnbr_fd(unsigned int n, int fd)
{
	unsigned int		temp;
	int					k;

	temp = n;
	k = 1;
	while (temp >= 16)
	{
		temp = temp / 16;
		k++;
	}
	ft_hexa_putnbr_innerfunc(n, fd);
	return (k);
}
