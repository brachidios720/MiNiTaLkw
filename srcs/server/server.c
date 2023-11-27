/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:49:39 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/11/11 00:00:04 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_DynamicBuffer	*init_dynamic_buffer(void)
{
	t_DynamicBuffer	*db;

	db = malloc(sizeof(*db));
	if (db == NULL)
		exit(1);
	db->length = 0;
	db->alloced = 1;
	db->data = malloc(db->alloced);
	db->data[0] = '\0';
	return (db);
}

void	add_char(t_DynamicBuffer *db, char character)
{
	if (db->data == NULL)
	{
		exit(1);
	}
	if (db->length + 1 >= db->alloced)
	{
		db->data = ft_realloc(db->data, db->alloced, db->alloced * 2);
		if (db->data == NULL)
		{
			exit(1);
		}
		db->alloced *= 2;
	}
	db->data[db->length] = character;
	db->data[db->length + 1] = '\0';
	db->length++;
}

void	recup(int c)
{
	static t_DynamicBuffer	*buffer;
	static char				character;
	static int				bit;

	if (buffer == NULL)
		buffer = init_dynamic_buffer();
	if (c == SIGUSR2)
		character |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		add_char(buffer, character);
		if (character == '\0')
		{
			ft_printf("%s\n", buffer->data);
			buffer->length = 0;
			buffer->data[0] = '\0';
		}
		bit = 0;
		character = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID :%d\n", pid);
	signal(SIGUSR1, recup);
	signal(SIGUSR2, recup);
	while (1)
	{
	}
	return (0);
}
