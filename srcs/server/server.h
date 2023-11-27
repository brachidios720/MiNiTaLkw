/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:15:32 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/11/13 17:49:36 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../../include/libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_dynamic
{
	char	*data;
	size_t	length;
	size_t	alloced;
}			t_DynamicBuffer;

void		recup(int c);
void		*ft_realloc(void *ptr, size_t oldsize, size_t newsize);

#endif
