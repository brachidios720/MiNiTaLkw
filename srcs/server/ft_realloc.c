/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:17:42 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/11/09 19:40:48 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	char	*newbuf;

	newbuf = malloc(sizeof(char) * newsize);
	ft_memcpy(newbuf, ptr, oldsize);
	free(ptr);
	return (newbuf);
}
