/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:56:43 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/11 11:56:50 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

// Reset
# define RESET       "\033[0m"

// Regular colors
# define BLACK       "\033[0;30m"
# define RED         "\033[0;31m"
# define GREEN       "\033[0;32m"
# define YELLOW      "\033[0;33m"
# define BLUE        "\033[0;34m"
# define MAGENTA     "\033[0;35m"
# define CYAN        "\033[0;36m"
# define WHITE       "\033[0;37m"

typedef struct s_control
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eat;
	int				status;
	long long		start_time;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
}	t_control;

typedef struct s_philo
{
	int				philo_id;
	int				eating_times;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	t_control		*ctl;
	struct s_philo	*next;
}	t_philo;

typedef struct timeval	t_time;

/* utils functions */
int			ft_atoi(char *str, int *err);
void		ft_clean(t_philo *tmp, t_control *ctl, int num);
int			check_if_full(t_philo *tmp);

/* time functions */
long long	ft_time(long long start_time, long long last_meal);
void		ft_usleep(int sleeptime);
void		ft_usleep_pro(int sleeptime, t_control *ctl);

/* initialization functions */
t_philo		*allocate_philo(int id, t_control *ctl);
void		philosophers_init(t_philo **head, t_control *ctl);
t_control	*controls_init(int ac, char **av, t_control *ctl);
t_control	*parsing(int ac, char **av);

/* algo utils functions */
void		write_message(long long time, t_philo *philo, char *str, char *str_color);
void		philo_cycle(t_philo *tmp, long long stime);
void		first_meal(t_philo *philo, long long stime);
void		one(t_philo *tmp);
void		multi_threads(t_philo *tmp, int num);
void		*routine(t_philo *philo);

#endif
