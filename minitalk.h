/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:24:47 by user              #+#    #+#             */
/*   Updated: 2025/06/02 17:12:40 by user             ###   ########.fr       */
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

#endif