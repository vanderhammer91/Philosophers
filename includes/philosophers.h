/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:52:38 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/29 13:34:49 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

typedef struct s_philo
{
	int				index;
	int				meals_til_full;
	int				is_full;
	long long		last_ate;
	long long		last_slept;
	char			status;
	pthread_t		thread_id;
	pthread_mutex_t	my_fork;
	pthread_mutex_t	is_alive;
	struct s_philo	*left;
	struct s_philo	*right;
	struct s_state	*rules;
}	t_philo;

typedef struct s_state
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				mealnum_req;
	int				overall_state;
	int				stop_flag;
	long long		start_time;
	pthread_mutex_t	print_mutex;
}	t_state;

//philo_routine.c
void	*philosopher_routine(void *m_philo);
void	run_routine(t_philo *m_philo);
void	*ft_run_monitor(void *m_philo);

//philo_utils.c
void	print_philo_state(t_philo *m_philo);
void	print_philosophers(t_philo **m_philosophers, int philo_count);
void	init_philosophers(t_state *m_state, t_philo **m_philosophers);

//list_utils.c
void	ft_free_list(t_philo *first);
void	ft_exit(t_philo **m_philosophers, char *error_msg);
void	ft_lstadd_back(t_philo **lst, t_philo *new_philo);
t_philo	*ft_lstlast(t_philo *lst);

//misc_utils.c
int		get_timestamp(void);
int		get_elapsed(t_state *rule_state);
void	ft_printbr(void);
void	ft_error(char *error_msg);
long	ft_atoi(const char *str);

//init_utils.c
void	populate_rules(int argc, char **argv, t_state *philo_state);

//routine_utils.c
void	print_status(t_philo *m_philo, char status_type);
void	ft_stop_routine(t_philo *m_philo);
int		noone_is_dead(t_philo *m_philo, int n);
int		everyone_is_full(t_philo *m_philo, int n);
int		m_round(int number);

//monitor_routine.c
int		philo_is_dead(t_philo *cur_philo);
int		a_philo_is_dead(t_philo *cur_philo);
void	*ft_run_monitor(void *m_philo);

#endif
