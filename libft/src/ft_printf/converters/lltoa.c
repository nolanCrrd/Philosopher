/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:35:28 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/07 08:47:36 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_lltoa(long long nbr)
{
	static char	buffer[22];
	char		*cursor;
	int			sign;

	ft_bzero(buffer, sizeof(buffer));
	cursor = &buffer[21];
	sign = 0;
	if (nbr < 0)
	{
		*--cursor = nbr % 10 * -1 + '0';
		nbr /= -10;
		sign = 1;
	}
	while (nbr / 10 != 0)
	{
		*--cursor = nbr % 10 + '0';
		nbr /= 10;
	}
	if (nbr > 0 || *(cursor) == 0)
		*--cursor = nbr % 10 + '0';
	if (sign)
		*--cursor = '-';
	return (cursor);
}
