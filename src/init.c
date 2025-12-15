/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:58:55 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/11 11:58:56 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	setup_forks(int id, t_control *ctl, t_philo *philo)
{
	if (id % 2)
	{
		philo->second_fork = &ctl->forks[id];
		if (philo->philo_id == 0)
			philo->first_fork = &ctl->forks[ctl->num_of_philo - 1];
		else
			philo->first_fork = &ctl->forks[id - 1];
	}
	else
	{
		philo->first_fork = &ctl->forks[id];
		if (philo->philo_id == 0)
			philo->second_fork = &ctl->forks[ctl->num_of_philo - 1];
		else
			philo->second_fork = &ctl->forks[id - 1];
	}
}

t_philo	*allocate_philo(int id, t_control *ctl)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->philo_id = id;
	philo->eating_times = 0;
	philo->next = NULL;
	philo->ctl = ctl;
	philo->last_meal = ctl->start_time;
	setup_forks(id, ctl, philo);
	return (philo);
}

void	philosophers_init(t_philo **head, t_control *ctl)
{
	int		i;
	t_philo	*tmp1;
	t_philo	*tmp2;

	i = 0;
	while (i < ctl->num_of_philo)
	{
		tmp1 = allocate_philo(i, ctl);
		if (i == 0)
		{
			tmp2 = tmp1;
			*head = tmp1;
		}
		else
		{
			tmp2->next = tmp1;
			tmp2 = tmp2->next;
		}
		i++;
	}
	tmp1->next = *head;
}

t_control	*controls_init(int ac, char **av, t_control *control)
{
	int	idx;

	idx = 0;
	control = malloc(sizeof(t_control));
	if (!control)
		return (NULL);
	control->num_of_philo = ft_atoi(av[1], &idx);
	control->time_to_die = ft_atoi(av[2], &idx);
	control->time_to_eat = ft_atoi(av[3], &idx);
	control->time_to_sleep = ft_atoi(av[4], &idx);
	control->num_eat = -1;
	if (ac == 6)
		control->num_eat = ft_atoi(av[5], &idx);
	if (idx || control->num_of_philo <= 0)
		return (free(control), NULL);
	pthread_mutex_init(&control->mutex, NULL);
	control->forks = malloc(sizeof(pthread_mutex_t) * control->num_of_philo);
	if (!control->forks)
		return (NULL);
	idx = 0;
	while (idx < control->num_of_philo)
		pthread_mutex_init(&control->forks[idx++], NULL);
	control->start_time = ft_time(-1, -1);
	control->status = 0;
	return (control);
}

t_control	*parsing(int ac, char **av)
{
	t_control	*control;

	if (ac < 5 || ac > 6)
		return (NULL);
	else
		control = controls_init(ac, av, NULL);
	if (!control)
		return (NULL);
	if (control->num_of_philo < 1)
		return (NULL);
	return (control);
}
