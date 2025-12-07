/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:36:36 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 15:29:31 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <sys/time.h>

void	set_actual_time(long *time_store, long start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	*time_store = (time.tv_sec * 1000 + time.tv_usec / 1000) - start;
}
