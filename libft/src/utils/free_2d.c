/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:23:29 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 10:24:57 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	free_2d(void **tab, void (*del)(void *))
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		del(tab[i]);
		i++;
	}
	free(tab);
}
