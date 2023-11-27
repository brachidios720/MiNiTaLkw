/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:01:37 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/11/07 16:38:58 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../../include/libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

void	ft_send_signal(int pid, char c);

#endif
