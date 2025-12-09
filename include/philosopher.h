/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:46:07 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 15:13:50 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif

# include <pthread.h>
# include <stddef.h>

typedef enum e_philo_state
{
	SLEEPING,
	THINKING,
	FORK1,
	FORK2,
	EATING,
	DEAD,
	FINISH,
	NOTHING,
	START,
}	t_philo_state;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				position;
}	t_fork;

typedef struct global_data
{
	long	start_time;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
	int		number_of_philosopher;
	int		number_of_eat;
	int		some_one_dead;
	t_fork	**forks;
}	t_global_data;

typedef struct s_philo
{
	int				philo_number;
	t_philo_state	state;
	long			last_eat;
}	t_philo;

typedef struct s_thread_monitoring
{
	t_philo			**philos;
	t_fork			**forks;
	t_global_data	*data;
}	t_thread_moni;

typedef struct s_thread_info
{
	t_fork			*left;
	t_fork			*right;
	t_philo			*philo;
	t_global_data	*data;
}	t_thread_info;

void			clear_philos(t_philo **philos);
void			clear_forks(t_fork **forks);
t_philo			**get_philo_list(size_t nb_philo);
t_global_data	*get_global_data(size_t nb_args, char **args);
t_fork			**get_fork_list(size_t nb_fork);
int				is_input_valid(size_t nb_args, char **args);
void			set_actual_time(long *time_store, long start);
void			*monitoring_routine(void *ptr);
int				init_threads_creation(pthread_t **threads_ids,
					t_thread_info ***infos,
					t_thread_moni **info_moni, t_global_data *data);
void			*philosopher_routine(void *ptr);

#endif
