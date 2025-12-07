/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:23:29 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/13 13:19:20 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief check if the given int is an ascii character
 * 
 * @param c int to check
 * @return int boolean
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
