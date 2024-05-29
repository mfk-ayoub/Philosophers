/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:34:16 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/29 06:38:00 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define ERROR_MSG " argument {[1] [2] [3] [4] and [5] optional argument}\n"
# define LINE_L "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n"
# define NUM_EAT "number of times each philosopher must eat\n"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

typedef struct s_input			t_input;
typedef struct s_philosopher	t_philosopher;

typedef struct s_input
{
	int							how_many;
	int							time_to_eating;
	int							time_to_sleeping;
	int							time_to_die;
	int							how_many_eat;
	t_philosopher				*philosophers;
	pthread_mutex_t				*forks;

}								t_input;

typedef struct s_philosopher
{
	int							id;
	int							times_eaten;
	int							last_meal_time;
	pthread_t					thread;
	pthread_mutex_t				*left_fork;
	pthread_mutex_t				*right_fork;
	t_input						*input;
}								t_philosopher;

int								ft_atoi(const char *str);
void							desplay_error(t_input *input, int ac,
									char **av);
void							desplay_message(t_input *input, char *message);
void							check_agrc(char **av);
long long						current_time(void);
void							eating(t_philosopher *philosopher);
void							sleeping(t_philosopher *philosopher);
void							thinking(t_philosopher *philosopher);

#endif