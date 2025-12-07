/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:24:08 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 15:27:55 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"
#include <stddef.h>
#include <stdlib.h>

t_global_data	*get_global_data(size_t nb_args, char **args)
{
	t_global_data	*global_data;
	size_t			i;
	int				value;

	global_data = ft_calloc(1, sizeof(t_global_data));
	if (global_data == NULL)
		return (NULL);
	i = 1;
	while (i < nb_args)
	{
		value = ft_atoi(args[i]);
		if (i == 1)
			global_data->number_of_philosopher = value;
		else if (i == 2)
			global_data->time_to_die = value;
		else if (i == 3)
			global_data->time_to_eat = value;
		else if (i == 4)
			global_data->time_to_sleep = value;
		else if (i == 5)
			global_data->number_of_eat = value;
		i++;
	}
	return (global_data);
}

t_fork	**get_fork_list(size_t nb_fork)
{
	t_fork	**forks;
	t_fork	*fork;
	size_t	i;

	forks = ft_calloc(nb_fork + 1, sizeof(t_fork *));
	i = 0;
	while (i < nb_fork)
	{
		fork = ft_calloc(1, sizeof(t_fork));
		if (fork == NULL)
		{
			clear_forks(forks);
			return (NULL);
		}
		if (pthread_mutex_init(&fork->mutex, NULL) != 0)
		{
			clear_forks(forks);
			return (NULL);
		}
		fork->position = i + 1;
		forks[i] = fork;
		i++;
	}
	return (forks);
}

t_philo	**get_philo_list(size_t nb_philo)
{
	t_philo	**philosophers;
	t_philo	*philo;
	size_t	i;

	philosophers = ft_calloc(nb_philo + 1, sizeof(t_philo *));
	if (philosophers == NULL)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		philo = ft_calloc(1, sizeof(t_philo));
		if (philo == NULL)
		{
			clear_philos(philosophers);
			return (NULL);
		}
		philo->state = START;
		philo->philo_number = i + 1;
		philosophers[i] = philo;
		i++;
	}
	return (philosophers);
}
