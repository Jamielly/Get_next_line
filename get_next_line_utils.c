/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:20:35 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/23 12:28:52 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	create_list(int fd, const char *ac)
{
	int	*buff;

	if (!fd || !ac)
		return (NULL);
	while (fd)
		read(fd, buff, BUFFER_SIZE);
	buff = malloc(sizeof(int));
	free(buff);
	buff = NULL;
	return (0);
}

static void	extract_line(int fd, char *line)
{
	int	line;

	line = create_list;
	if (line == '\n')
		break ;
	return (line);
}

static void	reclean_stash(int fd, const char *str)
{
	int	polish_list;

	extract_line();
}

static void	ft_strjoin(int fd, const char *s1, const char *s2)
{
	
}
