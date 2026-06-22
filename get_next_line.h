/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:41:09 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/22 13:41:09 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 10
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
    char    *str_buf;
    struct  s_list *next;
}   t_list;

char *get_next_line(int fd);



