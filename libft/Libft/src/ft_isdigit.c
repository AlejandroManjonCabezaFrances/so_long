/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:45:19 by amanjon-          #+#    #+#             */
/*   Updated: 2023/06/12 11:42:02 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isdigit(int c)
{
	if (c >= 0 && c <= 9)
		return (1);
	return (0);
}

/*int	main(void)
{
	int	c;

	c = '1';
	printf("%d", ft_isdigit(c));
	return (0);
}*/
