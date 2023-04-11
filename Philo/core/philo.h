/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:05:22 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/11 17:41:17 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_philo_must_eat;
	int			ac;
	long int	start;
}	t_data;

typedef struct s_philo
{
	t_data				*data;
	int					philo_id;
	int					nb_meals_eaten;
	long int			last_time_eaten;
	pthread_t			thread_id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		nb_meals_mutex;
	pthread_mutex_t		printf_mutex;
}	t_philo;

int			args_check(t_data *data);
int			init_philo(t_philo *philo, t_data *data, pthread_mutex_t *forks);
int			init_mutexes(pthread_mutex_t *forks, t_philo *philo, int nb_philo);
int			philo_thread(t_philo *philo, t_data *data, pthread_mutex_t *forks);
int			parsing(t_data *data, int argc, char **argv);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
void		philo_eat(t_philo *philo);
long int	gettime(void);
long int	get_timestamp(long int start);

#endif
