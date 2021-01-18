/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:20:29 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/15 15:20:30 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

#define SUM_PH	0
#define T_DIE	1
#define T_EAT	2
#define T_SLEEP	3
#define T_MST_E	4

#define LEFT	0
#define RIGHT	1

typedef struct		s_info
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	eat;
	pthread_mutex_t	l_check;
	int				amdead;
	int				rules[5];
}					t_info;

typedef struct		s_philo
{
	int				name;
	ssize_t			t_start;
	int				waf[2];
	pthread_t		th;
	ssize_t			last_eat;
	t_info			*info;
}					t_philo;

int					philo_pars(char **argv, int argc, t_info *info);
int					ft_atoi(const char *nptr);
ssize_t 			time_start(void);
long int			current_time(t_philo *philo);
void				true_sleep(int wait);
void				life_check(t_philo *phd);
void				if_eat(t_philo *phd);
void				init_philo(t_philo *phd);
void				ft_putnbr_light(ssize_t n);
void				forks_take(t_philo *phd);
void				right_forks_drop(t_philo *phd);
void				left_forks_drop(t_philo *phd);
int					every_day_the_same(t_philo *phd);
void				some_bussines(t_philo *phd, char *str, int n, int type);
void				mutex_wrap_chng(t_philo *phd, pthread_mutex_t *type, void f_chng());
void				mutex_wrap_writing(t_philo *phd, char * str, int n, void f_write());

#endif