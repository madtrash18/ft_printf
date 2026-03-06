/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:01:13 by djang             #+#    #+#             */
/*   Updated: 2024/03/17 14:01:15 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr_fd(char *s, int fd);
int		ft_putpercent(void);
void	ft_putnbr_fd(int n, int fd);
int		ft_putnbr_fd_counter(int n);
void	ft_unsigend_putnbr_fd(unsigned int n, int fd);
int		ft_unsigend_putnbr_fd_counter(unsigned int n);
void	ft_hexaupper_putnbr_innerfunc(unsigned int n, int fd);
int		ft_hexaupper_putnbr_fd(unsigned int n, int fd);
void	ft_hexa_putnbr_innerfunc(unsigned int n, int fd);
int		ft_hexa_putnbr_fd(unsigned int n, int fd);
void	ft_pointer_putnbr_innerfunc(unsigned long long n, int fd);
int		ft_pointer_putnbr_fd(unsigned long long n, int fd);
int		ft_printf_inner(va_list temp, char index);
int		ft_printf(const char *inserted_value, ...);

#endif
