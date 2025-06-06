/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:24:47 by user              #+#    #+#             */
/*   Updated: 2025/06/04 16:43:28 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <limits.h>
# include "printf/ft_printf.h"
# include <sys/types.h>
# include <unistd.h>

# ifndef WAIT_TIME
#  define WAIT_TIME 100
# endif

long	ex_atoi(const char *str);
void	display_error(char *message);

#endif