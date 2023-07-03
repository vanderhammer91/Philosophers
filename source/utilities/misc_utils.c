/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:18:51 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/21 19:23:55 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	get_timestamp(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	get_elapsed(t_state *rule_state)
{
	return (get_timestamp() - rule_state->start_time);
}

void	ft_printbr(void)
{
	printf("----------------------------------------------------\n");
}

void	ft_error(char *error_msg)
{
	write(2, "Error\n", 6);
	printf("%s", error_msg);
	exit(1);
}

long	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
