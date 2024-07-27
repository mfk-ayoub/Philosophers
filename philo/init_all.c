/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:10:42 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/07/27 19:46:04 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool philo_is_die(t_philo *philo, t_input *input)
{	
	int i;
	long current_time;
	
	i = 0;
    current_time = time_ms();
    while(i < input->how_many)
    {
        if (current_time - philo[i].last_meal > input->time_to_die)
        {
            philo[i].is_dead = true;
            printf("Philo %d has died\n", philo[i].id);
            return false;
        }
		i++;
    }
    return true;
}

int  join_and_execute(t_philo *philo, t_input *input)
{
	int i;
	
	i = -1;
	while (++i < input->how_many)
	{
		if (!!pthread_join(philo[i].philo_n, NULL))
			return (0);
	}
	while (1)
	{
		if (philo_is_die(philo,input) == false)
			break ;
	}
	return (1);
}
void	init_forks(t_philo *philo, t_input *input)
{
	int	i;

	(void)philo;
	input->forks = malloc(sizeof(t_fork) * input->how_many);
	if (!input->forks)
		return ;
	i = -1;
	while (++i < input->how_many)
	{
		input->forks[i].id = i;
		if (!!pthread_mutex_init(&input->forks[i].lock, NULL))
		{
			free(input->forks);
			return ;
		}
	}
}

int	init_philo(t_philo *philo, t_input *input)
{
	int	i;

	i = -1;
	init_forks(philo, input);
	while (++i < input->how_many)
	{
		philo[i].id = i + 1;
		philo[i].input = input;
		philo[i].l_forks = &input->forks[i];
		philo[i].r_forks = &input->forks[i + 1 % input->how_many];
		philo[i].meals_eaten = 0;
		philo[i].is_dead = true;
		philo[i].last_meal = time_ms();
		if (!!pthread_create(&philo[i].philo_n, NULL, &routine, &philo[i]))
			return (0);
	}
	if (!join_and_execute(philo,input))
		destory_all(philo);
	return (1);
}
