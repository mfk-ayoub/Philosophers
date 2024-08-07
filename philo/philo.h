/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:34:16 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/07/27 19:38:01 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

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

typedef struct s_input	t_input;
typedef struct s_philo	t_philo;

typedef struct s_fork
{
	int					id;
	pthread_mutex_t		lock;
}						t_fork;

typedef struct s_input
{
	int					how_many;
	int					time_to_eating;
	int					time_to_sleeping;
	int					time_to_die;
	int					how_many_eat;

	t_fork				*forks;
}						t_input;

typedef struct s_philo
{
	t_fork				*r_forks;
	t_fork				*l_forks;
	pthread_mutex_t		p_status;
	pthread_t			philo_n;
	bool				is_dead;
	int					meals_eaten;
	long 				last_meal;
	int					id;
	t_input				*input;

}						t_philo;

int						ft_atoi(const char *str);
void					desplay_error(t_input *input, int ac, char **av);
void					check_agrc(char **av);
int						init_philo(t_philo *philo, t_input *input);
void					*routine(void *argv);
void					init_forks(t_philo *philo, t_input *input);
void					destory_all(t_philo *philo);
long long				time_ms(void);
#endif
