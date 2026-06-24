/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:20:56 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/23 10:20:50 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char				*str_buf;
	struct s_list		*next;
}		t_list;

char	*get_next_line(int fd);

static void	ft_strlen(int fd, const char *str);
static void	create_list(int fd, const char *ac);
static void	extract_line(int fd, char *line);
static void reclean_stash(int fd, );
static void ft_strjoin(int fd, );
#endif