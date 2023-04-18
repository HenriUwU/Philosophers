/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:05:22 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/18 16:40:17 by hsebille         ###   ########.fr       */
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

typedef struct s_fork
{
	int				mutex_id;
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_data
{
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_philo_must_eat;
	int			is_dead;
	int			philo_satiated;
	long int	start;
	t_fork		*forks;
}	t_data;

typedef struct s_philo
{
	t_data				*data;
	int					philo_id;
	int					nb_meals_eaten;
	int					nb_forks;
	long int			last_time_eaten;
	pthread_t			thread_id;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_mutex_t		printf_mutex;
	pthread_mutex_t		is_dead_mutex;
	pthread_mutex_t		philo_satiated_mutex;
}	t_philo;

int			args_check(t_data *data);
int			init_philo(t_philo *philo, t_data *data);
int			init_mutexes(t_data *data, t_philo *philo, int nb_philo);
int			philo_thread(t_philo *philo, t_data *data);
int			parsing(t_data *data, int argc, char **argv);
int			ft_atoi(const char *nptr);
void		is_philo_dead(t_philo *philo);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		print_death(t_philo *philo);
long int	gettime(void);
long int	get_timestamp(long int start);

#endif
