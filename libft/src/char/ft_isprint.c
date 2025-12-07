/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:23:33 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/13 13:19:23 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief check if the given int is a character
 * 
 * @param c char to check
 * @return int boolean
 */
int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
