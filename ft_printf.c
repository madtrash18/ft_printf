/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:36:15 by djang             #+#    #+#             */
/*   Updated: 2024/03/08 21:36:17 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
version 6 :
헤더 파일 만들고 링크 고려
*/

#include "printf.h"

int	ft_printf_inner(va_list temp, char index)
{
	char			argchar;
	int				len;

	len = 0;
	if (index == 'd' || index == 'i')
		len = len + ft_putnbr_fd_counter(va_arg(temp, int));
	else if (index == 'c')
	{	
		argchar = va_arg(temp, int);
		len = len + ft_putchar(argchar);
	}
	else if (index == 'u')
		len = len + ft_unsigend_putnbr_fd_counter(va_arg(temp, unsigned int));
	else if (index == 's')
		len = len + ft_putstr_fd(va_arg(temp, char *), 1);
	else if (index == 'x')
		len = len + ft_hexa_putnbr_fd(va_arg(temp, unsigned int), 1);
	else if (index == 'X')
		len = len + ft_hexaupper_putnbr_fd(va_arg(temp, unsigned int), 1);
	else if (index == '%')
		len = len + ft_putpercent();
	else if (index == 'p')
		len = len + ft_pointer_putnbr_fd(va_arg(temp, unsigned long long), 1);
	return (len);
}

int	ft_printf(const char *inserted_value, ...)
{
	va_list			temp;
	int				k;
	int				len;

	if (inserted_value == NULL)
		return (-1);
	va_start(temp, inserted_value);
	k = 0;
	len = 0;
	while (inserted_value[k] != '\0')
	{
		if (inserted_value[k] == '%')
		{
			k++;
			len = len + ft_printf_inner(temp, inserted_value[k++]);
		}
		else
		{
			len = len + ft_putchar(inserted_value[k]);
			k++;
		}
	}
	va_end(temp);
	return (len);
}

/*
		if (inserted_value[k] == '%')
		{
			k++;
			len = len + ft_printf_inner(temp, inserted_value[k]);
			k++;
		}
		else
		{
			write(1, &inserted_value[k], 1);
			len++;
			k++;
		}
*/
