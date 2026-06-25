/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:20:15 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/23 10:16:27 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }

    stash = read_and_stash(fd, stash);
    if (!stash)
        return NULL;

    line = extract_line(stash);
    if (!line)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    stash = clean_stash(stash);

    return line;
}