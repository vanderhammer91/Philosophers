/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:45:47 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/21 18:57:43 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	ft_exit(t_philo **m_philosophers, char *error_msg)
{
	if (*m_philosophers)
		ft_free_list(*m_philosophers);
	write(2, "Error\n", 6);
	printf("%s", error_msg);
	exit(1);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	if (lst)
	{
		while (lst->right != NULL)
		{
			lst = lst->right;
		}
	}
	return (lst);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new_philo)
{
	t_philo	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->right = new_philo;
			new_philo->left = last;
		}
		else
		{
			*lst = new_philo;
			new_philo->left = NULL;
		}
		new_philo->right = NULL;
	}
}
