/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:13:33 by ivanderw          #+#    #+#             */
/*   Updated: 2023/07/02 12:35:42 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	print_status(t_philo *m_philo, char status_type)
{
	int	timestamp;
	int	index;

	timestamp = get_elapsed(m_philo->rules);
	index = m_philo->index;
	pthread_mutex_lock(&(m_philo->rules->print_mutex));
	if (status_type == 'T')
		printf("%s%d :\t %d is thinking.\n%s", RED, timestamp, \
				index + 1, RESET);
	else if (status_type == 'F')
		printf("%d :\t %d has taken a fork.\n", timestamp, index + 1);
	else if (status_type == 'E')
		printf("%s%d :\t %d is now eating.\n%s", YELLOW, timestamp, \
				index + 1, RESET);
	else if (status_type == 'S')
		printf("%s%d :\t %d is sleeping.\n%s", GREEN, timestamp, \
				index + 1, RESET);
	else if (status_type == 'D')
		printf("%s%d :\t %d has died! Should have used his hands!\n%s", \
				BLUE, timestamp, index + 1, RESET);
	else if (status_type == 'X')
		printf("%d :\t %d :[ERROR]: Pthread_create could not run correctly!\n", \
				timestamp, index + 1);
	pthread_mutex_unlock(&(m_philo->rules->print_mutex));
}

void	ft_stop_routine(t_philo *m_philo)
{
	m_philo->rules->stop_flag = 1;
	pthread_mutex_lock(&(m_philo->is_alive));
}

int	everyone_is_full(t_philo *m_philo, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (m_philo->meals_til_full != 0)
			return (0);
		m_philo = m_philo->right;
		i++;
	}
	return (1);
}

int	m_round(int num)
{
	int	remainder;

	remainder = num % 10;
	if (remainder >= 5)
		num += (10 - remainder);
	else
		num -= remainder;
	return (num);
}
