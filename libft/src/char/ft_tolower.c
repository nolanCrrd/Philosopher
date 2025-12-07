/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:24:08 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/13 13:20:32 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief return the given char into lower case
 * 
 * @param c char to convert
 * @return int converted char
 */
int	ft_tolower(int c)
{
	return (c + ((c >= 'A' && c <= 'Z') * 32));
}
