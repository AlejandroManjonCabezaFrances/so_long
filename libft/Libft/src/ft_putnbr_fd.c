/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:01:31 by amanjon-          #+#    #+#             */
/*   Updated: 2023/06/14 10:59:53 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar('-', fd);
		ft_putchar('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-', fd);
		n = n * (-1);
	}
	if (n <= 9)
	{
		n = n + '0';
		ft_putchar(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

/* int main(void)
{
	ft_putnbr_fd(875, 1);
	return (0);
} */
