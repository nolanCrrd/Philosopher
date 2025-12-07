/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:12:38 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 15:30:36 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <sys/time.h>
#include <unistd.h>

static int	post_eating_routine(t_thread_info *info, int eated)
{
	if (info->data->number_of_eat == eated)
	{
		info->philo->state = FINISH;
		pthread_mutex_unlock(&info->left->mutex);
		pthread_mutex_unlock(&info->right->mutex);
		return (1);
	}
	pthread_mutex_unlock(&info->left->mutex);
	pthread_mutex_unlock(&info->right->mutex);
	info->philo->state = SLEEPING;
	usleep(info->data->time_to_sleep * 1000);
	return (0);
}

static int	pre_eating_routine(t_thread_info *info)
{
	long	actual_time;

	info->philo->state = THINKING;
	pthread_mutex_lock(&info->left->mutex);
	info->philo->state = FORK1;
	pthread_mutex_lock(&info->right->mutex);
	info->philo->state = FORK2;
	info->philo->state = EATING;
	set_actual_time(&actual_time, info->data->start_time);
	info->philo->last_eat = actual_time;
	usleep(info->data->time_to_eat * 1000);
	return (0);
}

void	*philosopher_routine(void *ptr)
{
	t_thread_info	*info;
	long			actual_time;
	int				eated;

	info = (t_thread_info *)ptr;
	set_actual_time(&actual_time, info->data->start_time);
	info->philo->last_eat = actual_time;
	eated = 0;
	while (1)
	{
		if (info->data->some_one_dead)
			return (NULL);
		pre_eating_routine(info);
		eated++;
		if (post_eating_routine(info, eated))
			return (NULL);
	}
	return (NULL);
}
